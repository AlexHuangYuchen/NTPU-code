#include<iostream>
#include<vector>
#include <random>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;
enum class Suit{Spades,Hearts,Diamonds,Clubs};//花色(列舉資料型別)
class Card{//牌
public:
int number;//編號
Suit suit;//哪個花色
Card(int number,Suit suit){
    this->number=number;
    this->suit=suit;
}
string get_suit_name(Suit suit ){//取得花色名稱
    switch(suit){
        case Suit::Hearts:return "Hearts";break;
        case Suit::Diamonds:return "Diamonds";break;
        case Suit::Clubs:return "Clubs";break;
        case Suit::Spades:return "Spades";break;
    }
    return "";

}
string get_card_name(int number){//取得牌名稱
    string card_name="";
    if(number==1){
        card_name="A";
    }else if(number==11){
        card_name="J";
    }else if(number==12){
        card_name="Q";
    }else if(number==13){
        card_name="K";
    }else{
        card_name=to_string(number);
    }
    return card_name;

}
};
class Deck{//牌堆
public:
    vector<Card> cards;//牌組
    Deck(){
        produce_deck();//生成牌組
    }
    void produce_deck(){//生成牌組
        cards.clear();//清空牌組
        for(int i=0;i<=3;i++){
            for(int j=1;j<=13;j++){
                cards.push_back(Card(j,static_cast<Suit>(i)));
            }
        }
    }
    void shuffle_deck(){//洗牌
        random_device rd;
        //mt19937 g(rd());
        mt19937 g(static_cast<unsigned>(time(0)));
        shuffle(cards.begin(),cards.end(),g);//隨機打亂牌組
    }
    Card draw(){
        if(cards.empty()){
            cout<<"No more cards to draw"<<endl;//如果沒有牌可以抽了
            return Card(0, Suit::Spades);
        }
        else{
            Card top=cards.back();//抽出最後一張牌
            cards.pop_back();//移除最後一張牌
            return top;//返回抽到的牌
        }
    }
};
class Player{//玩家
public:
    bool isEliminated ;
    int id;//玩家編號
    int sorted_id;//排序編號
    bool is_human;//判斷是否為人類玩家
    vector<Card> hand_cards;//手牌
    int point;//分數
    Player(int id,bool is_human){
        this->id=id;
        this->sorted_id=id;
        this->is_human=is_human;
        this->isEliminated=false;
        this->point=0;
    }
};
int use_special_card=0;//紀錄是否使用特殊牌
int designate_player_index;//指定玩家
class Game{//遊戲管理
public:
    vector<Player> players;//玩家
    int current_score;//當前分數
    int total_rounds;//總回合數
    int turn;//輪到哪位玩家
    Deck deck;//一組牌堆
    int player_num;//玩家數量
    Game(int player_num,int rounds){//建構子
        current_score=0;
        total_rounds=rounds;
        this->player_num=player_num;
        turn=0;
        for(int i=1;i<=player_num;i++){
            if(i==1){
                players.push_back(Player(i,true));
            }
            else{
                players.push_back(Player(i,false));
            }
        }
    }
    void start_game(){//啟動遊戲
        cout<<"==========Game Start=========="<<endl;
        for(int i=0;i<total_rounds;i++){
            cout<<"==========The "<<i+1<<" round begins=========="<<endl;
            one_round_game();//進行一回合遊戲
        }
        cout<<"==========Game Over=========="<<endl;
        //開始排最終積分
        for(int i=0;i<players.size()-1;i++){
            for(int j=i+1;j<players.size();j++){
                if(players[i].point<players[j].point){
                    swap(players[i],players[j]);
                }
            }
        }
        int current_point=-1;//當前分數
        int rank=0;//排名
        for(int i=0;i<players.size();i++){
            if(players[i].point!=current_point){//如果分數不同
                rank++;
                cout<<endl;
                cout<<"No "<<rank<<":";
                current_point=players[i].point;
                if(players[i].is_human==true){
                    cout<<" You"<<"->"<<players[i].point;
                }
                else{
                    cout<<" Player "<<players[i].id<<"->"<<players[i].point;
                }
            }
            else{
                if(players[i].is_human==true){
                    cout<<" You"<<"->"<<players[i].point;
                }
                else{
                    cout<<" Player "<<players[i].id<<"->"<<players[i].point;
                }
            }
        }
    }
    void one_round_game(){//一回合遊戲
        current_score=0;
        deck.produce_deck();
        deck.shuffle_deck();
        cout<<endl;
        cout<<"Draw cards to determine order"<<endl;
        vector<Card>drawn_cards;//抽到的牌
        vector<Card>rem_drawn_cards;//紀錄抽到的牌
        drawn_cards.clear();//清空抽到的牌
        rem_drawn_cards.clear();//清空紀錄抽到的牌
        for(int i=0;i<players.size();i++){
            Card the_card_be_drawn=deck.cards.back();//抽出最後一張牌
            deck.cards.pop_back();//移除最後一張牌
            drawn_cards.push_back(the_card_be_drawn);//加入抽到的牌
            rem_drawn_cards.push_back(the_card_be_drawn);//加入紀錄抽到的牌
            if(i+1==1){
                cout<<"You drew a card: "<<the_card_be_drawn.get_card_name(the_card_be_drawn.number)<<" "<<the_card_be_drawn.get_suit_name(the_card_be_drawn.suit)<<endl; 
            }
            else{
                cout<<"Player "<<i+1<<" drew a card: "<<the_card_be_drawn.get_card_name(the_card_be_drawn.number)<<" "<<the_card_be_drawn.get_suit_name(the_card_be_drawn.suit)<<endl; 
            }
        };
        
        // 使用自定義比較函數排序
        auto compare_cards = [](const Card& a, const Card& b) {
        if (a.number != b.number) {
            return a.number > b.number; // 按牌面數字從大到小排序
        }
        // 定義花色優先順序：黑桃 > 紅心 > 方塊 > 梅花
        auto suit_priority = [](Suit suit) {
            switch (suit) {
                case Suit::Spades: return 0;   // 黑桃
                case Suit::Hearts: return 1;   // 紅心
                case Suit::Diamonds: return 2; // 方塊
                case Suit::Clubs: return 3;    // 梅花
            }
            return 4; // 預設值（不應該到這裡）
        };
        return suit_priority(a.suit) < suit_priority(b.suit); // 按花色優先順序排序
        };

         std::sort(drawn_cards.begin(), drawn_cards.end(), compare_cards);
        
        vector<Player> sortedPlayers;
        sortedPlayers.clear();//清空排序後的玩家
        for(int i=0;i<drawn_cards.size();i++){
            for(int j=0;j<rem_drawn_cards.size();j++){
                if(drawn_cards[i].number==rem_drawn_cards[j].number && drawn_cards[i].suit==rem_drawn_cards[j].suit){
                    players[j].sorted_id=i+1;
                    players[j].isEliminated=false;
                    sortedPlayers.push_back(players[j]);
                    break;
                }
            }
        }
        cout<<endl;
        cout<<"Order of play in this round-> ";
        for(int i=0;i<sortedPlayers.size();i++){
            if(sortedPlayers[i].is_human==true){
                 cout<<"You ";
             }
             else{
                 cout<<"Player "<<sortedPlayers[i].id<<" ";
             }
        }

        cout<<endl;
        deck.produce_deck();
        deck.shuffle_deck();
        players=sortedPlayers;
        for(int i=0;i<players.size();i++){
            players[i].hand_cards.clear();//清空手牌
            for(int j=0;j<5;j++){
                players[i].hand_cards.push_back(deck.draw());//抽牌
            }
        } 
        turn=0;//從第一位玩家開始
        play_turns();//開始進行回合
        std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
            return a.id < b.id; // 按 ID 由小到大排序
        });
    }
    bool canplay(Player &player){
        for(int i=0;i<player.hand_cards.size();i++){
            int predicted_score=current_score;
            switch (player.hand_cards[i].number){
                case 1:
                    if(static_cast<int>(player.hand_cards[i].suit)==0){
                        return true;
                    }
                    else{
                        predicted_score+=1;
                    }
                    break;
                case 2: case 3: case 6: case 7: case 8: case 9:
                    predicted_score+=player.hand_cards[i].number;
                    break;
                case 4: case 5: case 10: case 11: case 12: case 13: 
                    return true;
                    break;
            }
            if(predicted_score<=99){
                return true;
            }
        }
        return false;
    }
    void play_turns(){
        vector<Player> finishedOrder;//紀錄已經完成的玩家
        vector<Player> eliminatedOrder;//紀錄被淘汰的玩家
        int last_player=player_num;//紀錄剩下的玩家人數
        while(last_player>1){
            Player &currentPlayer = players[turn];//這是reference當前玩家
            if(currentPlayer.isEliminated==true){
                turn=(turn+1)%players.size();//如果當前玩家被淘汰，則輪到下一位玩家
                continue;
            }
            if(currentPlayer.is_human==true){
                cout<<"Your turn! ";
                cout<<"Current score: "<<current_score<<endl;
                cout<<"Your hand cards: ";
                for(int i=0;i<currentPlayer.hand_cards.size();i++){
                    cout<<"["<<currentPlayer.hand_cards[i].get_card_name(currentPlayer.hand_cards[i].number)<<" "<<currentPlayer.hand_cards[i].get_suit_name(currentPlayer.hand_cards[i].suit)<<"]"<<" ";
                }
            }
            else{
                cout<<"Player "<<currentPlayer.id<<"'s turn ";
                cout<<"Current score: "<<current_score<<endl;
            }///////
            if (canplay(currentPlayer)==false) {//如果無法出牌
                if(currentPlayer.is_human==true){
                    cout<<"You have no playable cards and no functional cards, you are eliminated";
                }
                else{
                    cout<<"Player "<<currentPlayer.id<<" has no playable cards and no functional cards, they are eliminated";
                }
                currentPlayer.isEliminated = true;
                eliminatedOrder.push_back(currentPlayer);//加入淘汰的玩家
                currentPlayer.point+=eliminatedOrder.size();
                cout<<" Gain "<<eliminatedOrder.size()<<" points"<<endl;
                last_player--;//剩下的玩家人數減1
                if (last_player <= 1) {
                    cout << "Game over. Only one player remains." << endl;
                    break;
                }
                turn = (turn + 1) % players.size();//輪到下一位玩家
                continue;
            }
            int cardIndex = choose_card(currentPlayer);
            play_card(currentPlayer,cardIndex);//出牌
            if(currentPlayer.hand_cards.empty()==1 && current_score<99){
                if(currentPlayer.is_human==true){
                    cout<<"You have no cards left, you are finished";
                }
                else{
                    cout<<"Player "<<currentPlayer.id<<" has no cards left, they are finished";
                }
                currentPlayer.isEliminated = true;
                finishedOrder.push_back(currentPlayer);//加入完成的玩家
                cout<<" Gain "<<player_num-finishedOrder.size()+1<<" points"<<endl;
                currentPlayer.point+=player_num-finishedOrder.size()+1;
                last_player--;
                if (last_player <= 1) {
                    cout << "Game over. Only one player remains." << endl;
                    break;
                }
            }
            if(current_score>99 && use_special_card==0){//如果分數大於等於99
                if(currentPlayer.is_human==true){
                    cout<<"You have reached 99 points, you are finished.";
                }
                else{
                    cout<<"Player "<<currentPlayer.id<<" has reached 99 points, it is finished.";
                }
                currentPlayer.isEliminated = true;
                eliminatedOrder.push_back(currentPlayer);//加入完成的玩家
                cout<<" Gain "<<eliminatedOrder.size()<<" points"<<endl;
                currentPlayer.point+=eliminatedOrder.size();
                last_player--;
                if (last_player <= 1) {
                    cout << "Game over. Only one player remains." << endl;
                    break;
                }
            }
            if(designate_player_index!=-1){
                if(currentPlayer.is_human==true){
                    cout<<"You have designated Player "<<players[designate_player_index].id<<" to play a card"<<endl;
                }
                else{
                    cout<<"Player "<<currentPlayer.id<<" has designated Player "<<players[designate_player_index].id<<" to play a card"<<endl;
                }
                turn=designate_player_index;//指定玩家出牌
                designate_player_index=-1;//重置指定玩家
            }
            else{
                turn = (turn + 1) % players.size();//輪到下一位玩家
            }
        }
        for(int i=0;i<players.size();i++){
            if(players[i].isEliminated==false){
                if(players[i].is_human==true){
                    cout<<"You gain "<<player_num-finishedOrder.size()+1-1<<" points"<<endl;
                    players[i].point+=player_num-finishedOrder.size()+1-1;
                }
                else{
                    cout<<"Player "<<players[i].id<<" gain "<<player_num-finishedOrder.size()+1-1<<"points"<<endl;
                    players[i].point+=player_num-finishedOrder.size()+1-1;
                }
            }
        }
        cout<<"This round ends!"<<endl;
        cout<<"======================================================================================================="<<endl;
        cout<<"|";
        for(int i=1;i<=players.size();i++){
            for(int j=0;j<players.size();j++){
                if(players[j].id==i){
                    if(i==1){
                        cout<<"Your ";
                    }
                    else{
                        cout<<"Player "<<players[j].id<<"'s ";
                    }
                    cout<<"score: "<<players[j].point<<" |";
                    break;
                }
            }
        }
        cout<<endl;
        cout<<"========================================================================================================"<<endl;
    }
    void play_card(Player &player, int cardIndex) {
        if (player.hand_cards.empty() || cardIndex < 0 || cardIndex >= player.hand_cards.size()) {
            cout << "Invalid card index" << endl;
            return;
        }
        Card played_card = player.hand_cards[cardIndex]; // 出牌
        if (player.is_human == true) {
            cout << "You played: " << played_card.get_card_name(played_card.number) << " " << played_card.get_suit_name(played_card.suit) << endl;
        } else {
            cout << "Player " << player.id << " played: " << played_card.get_card_name(played_card.number) << " " << played_card.get_suit_name(played_card.suit) << endl;
        }
        player.hand_cards.erase(player.hand_cards.begin() + cardIndex); // 移除出牌的牌
        card_effect(player, played_card); // 執行出牌效果
        if (player.hand_cards.size() < 5 && !deck.cards.empty()) { // 確保手牌不超過 5 張
            player.hand_cards.push_back(deck.draw()); // 抽一張牌
        }
    }
    void card_effect(Player&player,Card play_card){
        use_special_card=0;//重置使用特殊牌的標記
        designate_player_index=-1;//指定玩家
        switch(play_card.number){
            case 1:
                if (static_cast<int>(play_card.suit)!= 0){
                    current_score += 1;
                }
                else{
                    current_score=0;
                }
                break;
            case 2: case 3: case 6: case 7: case 8: case 9:
                current_score += play_card.number;
                break;
            case 4:
                if (players.size() == 4) {
                    reverse(players.begin(), players.end());
                    turn = players.size() - 1 - turn; // 修正當前玩家索引
                    
                    // 確保 turn 指向未被淘汰的玩家
                    while (players[turn].isEliminated) {
                        turn = (turn + 1) % players.size();
                    }
                    cout << "order reverse" << endl;
                } else {
                    current_score += 4;
                }
                break;
                case 5:
                    use_special_card = 1;
                    if (player.is_human == true) {
                    cout << "Choose the designated player to play card[--enter the bellow player's id(if player 3 enter 3)--]:" << endl;
            
                    // 顯示未被淘汰的玩家
                    for (int i = 0; i < players.size(); i++) {
                        if (!players[i].isEliminated && players[i].id != player.id) { // 排除自己和已被淘汰的玩家
                            cout << "Player " << players[i].id << " ";
                        }
                    }
                    cout << endl;
            
                    int player_id;
                    cin >> player_id;
                    cout << endl;
            
                    // 檢查輸入是否有效
                    bool valid_choice = false;
                    for (int i = 0; i < players.size(); i++) {
                        if (players[i].id == player_id && !players[i].isEliminated && players[i].id != player.id) {
                            designate_player_index = i;
                            valid_choice = true;
                            break;
                        }
                    }
            
                    if (!valid_choice) {
                        cout << "Invalid choice! Please choose again." << endl;
                        return card_effect(player, play_card); // 重新執行效果
                    }
            
                    cout << "Player " << players[designate_player_index].id << "'s turn" << endl;
                    } else {
                        // 過濾存活的玩家
                        vector<int> alive_indices;
                        for (int i = 0; i < players.size(); i++) {
                            if (!players[i].isEliminated && players[i].id != player.id) { // 排除自己
                                alive_indices.push_back(i);
                            }
                        }
                
                        // 隨機選擇存活的玩家
                        if (!alive_indices.empty()) {
                            int random_index = rand() % alive_indices.size();
                            designate_player_index = alive_indices[random_index];
                            cout << "Player " << players[designate_player_index].id << "'s turn" << endl;
                        } else {
                            cout << "No valid players to designate." << endl;
                        }
                    }
                    break;
            case 10:
            if (player.is_human) {
                cout<<"+10 or -10(enter 1 + , enter 0 -)"<<endl;
                int c = Choice();
                if(c==1){
                    current_score += 10;
                }
                else{
                    current_score -= 10;
                }
            } else {
                if(rand() % 2 == 1){
                    current_score += 10;
                }
                else{
                    current_score -= 10;
                }
            }
            break;
            case 11: // J
                use_special_card=1;
                turn = (turn + 1) % players.size();
                cout << "skipped" << endl;
                break;
            case 12: // Q
                if (player.is_human) {
                    cout<<"+20 or -20(enter 1 + , enter 0 -)"<<endl;
                    int c = Choice();
                    if(c==1){
                        current_score += 20;
                    }
                    else{
                        current_score -= 20;
                    }
                } else {
                    if(rand() % 2 == 1){
                        current_score += 20;
                    }
                    else{
                        current_score -= 20;
                    }
                }
                break;
            case 13: // K
                current_score = 99;
                break;
        }
    }
    int Choice() {
        int choice;
        cin>>choice;
        if (choice != 1 && choice != 0) {
            cout << "Invalid choice! Please choose again." << endl;
            return Choice();
        }
        return choice;
    }
    int choose_card(Player &player){//人類玩家選擇手牌
        if(player.is_human==true){
            int cardindex;
            cout<<"Choose a card to play (1~"<<player.hand_cards.size()<<"): ";
            cin>>cardindex;
            cardindex--;
            if(cardindex<0 || cardindex>=player.hand_cards.size()){
                cout<<"Invalid choice! Please choose again."<<endl;
                return choose_card(player);
            }
            return cardindex;
        }
        else{
            return rand() % player.hand_cards.size();//電腦玩家隨機選擇一張牌
        }

    }
};
using namespace std;
int main(){
    srand(static_cast<unsigned>(time(0)));//隨機數種子
    int player_num;
    int rounds;
    cout<<"Enter the number of players(2~5 people): ";
    cin>>player_num;
    cout<<"Enter the number of rounds to play: ";
    cin>>rounds;
    Game game(player_num, rounds);
    game.start_game();

    return 0;
}