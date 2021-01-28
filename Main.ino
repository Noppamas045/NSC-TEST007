#define ButtonBlack  14
#define ButtonRed 15
#define ButtonBlue 17
int ButtonYellow = 16;
int ButtonGreen = 18;
long ButtonA = 0; //1
long ButtonB = 0; //2
long ButtonC = 0; //3
int ButtonD = 0; //4

int Xnum;
int XHp;
int XDoor;
int XGem;
int XShield;
int XFreze;
int Xstart;

int roll;
int next;
int End;

int BossA;
int BossB;
int BossC;
int BossD;

int Astart = 1 ;
int Anum;
int AHp;
int AGem;
int ADoor;
int AShield;
int AFreze;

int Bstart = 11 ;
int Bnum;
int BHp;
int BGem;
int BDoor;
int BShield;
int BFreze;

int Cstart = 21 ;
int Cnum;
int CHp;
int CGem;
int CDoor;
int CShield;
int CFreze;

int Dstart = 31 ;
int Dnum;
int DHp;
int DGem;
int DDoor;
int DShield;
int DFreze;
//รอลบ
int XnextGem;

void setup(){
Serial.begin(9600);
Anum=Astart;
Bnum=Bstart;
Cnum=Cstart;
Dnum=Dstart;

ButtonA=0;
    for(int i = 0 ; i <=4 ; i++){
if(digitalRead(ButtonBlack)==0 && digitalRead(ButtonRed)==0){

while (digitalRead(ButtonBlack)==0  && digitalRead(ButtonRed)==0 ) {}

}
if (i == 1 && digitalRead(ButtonRed)==0 ) {
     Serial.println("2");
     ButtonA=0;
     delay(500);

}else if(i == 2 && digitalRead(ButtonRed)==0)
{
    Serial.println("3");
    ButtonA=3;
    delay(500);
}else if(i == 3 && digitalRead(ButtonRed)==0 )
{
    Serial.println("4");
    ButtonA=4;
    delay(500);

}

else if(i == 4 && digitalRead(ButtonRed)==0){
    i=0;
}


}

Serial.println("\tWelcome\n");
delay(1000);
 if(ButtonA==0) {
AHp = 5;
BHp = 5;

Serial.println("\t2 Player");
}
else if(ButtonA==3) {
AHp = 5;
BHp = 5;
CHp = 5;
Serial.println("\t3 Player");
}
else if(ButtonA==4) {
AHp = 5;
BHp = 5;
CHp = 5;
DHp = 5;

Serial.println("\t4 Player");
}

}


 
void loop(){
    do{
        if(AHp>0) {
        AOperation();
            if(BHp>0) {
            BOperation();
                if(CHp>0){
                COperation();
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
                else if (CHp<1) {
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
            }
            else if(BHp<1){
                if(CHp>0){
                COperation();
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
                else if (CHp<1) {
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
            }   
        }
        else if(AHp<1){
           if(BHp>0) {
            BOperation();
                if(CHp>0){
                COperation();
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
                else if (CHp<1) {
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
            }
            else if(BHp<1){
                if(CHp>0){
                COperation();
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
                else if (CHp<1) {
                    if(DHp>0){
                    DOperation();
                    
                    }
                    else if(DHp<1){

                    }   
                }
            }   
        }

if(AHp>0 && BHp<1 && CHp<1 && DHp<1 || ADoor>=7 && BDoor<7 && CDoor<7 && DDoor<7){
    Serial.println("A win");
    End++;
}
else if(AHp<1 && BHp>0 && CHp<1 && DHp<1 || ADoor<7 && BDoor>=7 && CDoor<7 && DDoor<7)
{
    Serial.println("B win");
    End++;
}
else if(AHp<1 && BHp<1 && CHp>0 && DHp<1 || ADoor<7 && BDoor<7 && CDoor>=7 && DDoor<7)
{
    Serial.println("C win");
    End++;
}
else if(AHp<1 && BHp<1 && CHp<1 && DHp>0 || ADoor<7 && BDoor<7 && CDoor<7 && DDoor>=7)
{
    Serial.println("D win");
    End++;
}
    }while(End<1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AOperation()
{
 Xnum=0;
 XHp=0;
 XDoor=0;
 XGem=0;
 XShield=0;
 XFreze=AFreze;
 Xstart=0;
do {
XFreze = XFreze + 1 ;

if (XFreze<1) {
next++;
Serial.println("\tFreze hold for next round");

}

else if (XFreze>0) {
roll=random(1,6);

while (digitalRead(ButtonYellow)==0) {
//จอบอกให้กดปุ่ม 
Serial.println("\t\tPush Button to play");
}
Anum+=roll;
 Xnum=Anum;
 XHp=AHp;
 XDoor=ADoor;
 XGem=AGem;
 XShield=AShield;
 Xstart=Astart;

while (Xnum>40) {

if(Xnum>40)
{
    Xnum = Xnum%40;
}
else {

}
}    
Serial.println(Xnum);
        if(Xnum==1||Xnum==11||Xnum==21||Xnum==31)
        {
            //เก็บหิน
            XDoor = XDoor+XGem ;
            XGem  = 0 ;
            Serial.println(" Send Gem to door ");
        }
        else if(Xnum==2||Xnum==12||Xnum==22||Xnum==32)
        {
            //เสียหิน
            if(XGem>0)
            {
                XGem = XGem - 1 ;
                Serial.println(" Lost one Gem");
                //next
            }
            else 
            {
                Serial.println("No Gem pass");
                //next
            }
        }
        else if(Xnum==3||Xnum==9||Xnum==13||Xnum==19||Xnum==23||Xnum==29||Xnum==33||Xnum==39)
        {
            //ได้หิน
            XGem = XGem + 1 ;
            Serial.println(" Get one Gem");
            //next
        }
        else if(Xnum==4||Xnum==8||Xnum==14||Xnum==18||Xnum==24||Xnum==28||Xnum==34||Xnum==38)
        {
            //สุ่มสกิล
            //กดปุ่ม
            roll = random(1,6);
            while (digitalRead(ButtonYellow)==0) {
            //จอบอกให้กดปุ่ม
            Serial.println("\t\tPush Button to play");
            }
            Serial.println(roll);
            if(roll == 1)   //Freeze
            {
                XFreze = (XFreze * 0) - 1 ;
                Serial.println("\t*Freze*");
                //next
            }
            else if (roll == 2)     //Toxic
            {
                XHp = XHp - 2 ;
                Serial.println("\t*Toxic*");
                //next
            }
            else if (roll == 3)     // Rewind
            {
                Serial.println("\t*Rewind*");
                if(Xnum == 4||Xnum == 14||Xnum == 24||Xnum == 34)   // GetGem
                {
                    XGem = XGem + 1 ;
                    Serial.println("\t*And get Gem*");
                    if(Xnum == 4)
                    {
                        Xnum = 3 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 13 ;
                        //next
                    }
                    else if(Xnum == 24)
                    {
                        Xnum = 23 ;
                        //next
                    }
                    else if(Xnum == 34)
                    {
                        Xnum = 33 ;
                        //next
                    }
                }
                else if(Xnum == 8||Xnum == 18)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 8)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 28||Xnum == 38)     // Damage
                {
                    Serial.println("\t*And Damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 28)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 38)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                
            }
            else if (roll == 4)     // Shield
            {
                XShield = 1 ;
                Serial.println("\t*Get Shield*");
                //next
            }
            else if (roll == 5)     //Triple
            {
                Serial.println("\t*Triple*");
                if(Xnum == 8||Xnum == 18||Xnum == 28||Xnum == 38)   // Door
                {
                    Serial.println("\t*And go to door*");
                    XDoor = XDoor+XGem ;
                    XGem  = 0 ;
                    if(Xnum == 8)
                    {
                        Xnum = 11 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 21 ;
                        //next
                    }
                    else if(Xnum == 28)
                    {
                        Xnum = 31 ;
                        //next
                    }
                    else if(Xnum == 38)
                    {
                        Xnum = 1 ;
                        //next
                    }
                }
                else if(Xnum == 4||Xnum == 14)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 4)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 24||Xnum == 34)     // Damage
                {
                    Serial.println("\t*And damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 24)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 34)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                //next
            }

            else if (roll == 6)     //Power shot
            {
                Serial.println("\t*Power Shot*");
                if(Xnum == 4||Xnum == 8)
                {
                    if(BossA == 1)
                    {
                        BossA = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 14||Xnum == 18)
                {
                    if(BossB == 1)
                    {
                        BossB = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");//next
                    }
                }
                if(Xnum == 24||Xnum == 28)
                {
                    if(BossC == 1)
                    {
                        BossC = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 34||Xnum == 38)
                {
                    if(BossD == 1)
                    {
                        BossD = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                       Serial.println("\tClear pass");
                        //next
                    }
                }
            }
        }
        else if(Xnum==5||Xnum==15||Xnum==27||Xnum==37)
        {
            //เสียเลือด 1
            XHp = XHp - 1 ;
            Serial.println("\tDamage -1 Hp");
            //next
        }
        else if(Xnum==6||Xnum==16||Xnum==26||Xnum==36)
        {
            //ขโมย
            if (XnextGem>0)
            {
            XnextGem = XnextGem - 1 ;
            XGem = XGem + 1 ;
            Serial.println("\tSteal Stone from Next player");
            //next 
            }
            else {
            Serial.println("\tPass");
            //next
            }
        }
        else if(Xnum==7||Xnum==17||Xnum==25||Xnum==35)
        {
            //ฮิล
            XHp = XHp + 1 ;
            Serial.println("\tGet 1 Hp");
            //next
        }
        else if(Xnum==10||Xnum==20||Xnum==30||Xnum==40)
        {
            //บอส
            if (Xnum == 10) 
            {
                if(BossA == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 20) 
            {
                if(BossB == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 30) 
            {
                if(BossC == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 40) 
            {
                if(BossD == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
 
        } 
next++;
Anum=Xnum;
 AHp=XHp;
 ADoor=XDoor;
 AGem=XGem;
 AShield=XShield;
 AFreze=XFreze;
 Serial.print("\tYour position = ");
 Serial.print(Anum);
 delay(1000);
    }   //Check Freze
 }while (next < 1);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//B




void BOperation(){
 Xnum=0;
 XHp=0;
 XDoor=0;
 XGem=0;
 XShield=0;
 XFreze=BFreze;
 Xstart=0;
 
do {
XFreze = XFreze + 1 ;

if (XFreze<1) {
next++;
Serial.println("\tFreze hold for next round");

}

else if (XFreze>0) {
roll=random(1,6);

while (digitalRead(ButtonBlack)==0) {
//จอบอกให้กดปุ่ม 
Serial.println("\t\tPush Button to play");
}
Bnum+=roll;
 Xnum=Bnum;
 XHp=BHp;
 XDoor=BDoor;
 XGem=BGem;
 XShield=BShield;
 Xstart=Bstart;

while (Xnum>40) {

if(Xnum>40)
{
    Xnum = Xnum%40;
}
else {

}
}    
Serial.println(Xnum);
        if(Xnum==1||Xnum==11||Xnum==21||Xnum==31)
        {
            //เก็บหิน
            XDoor = XDoor+XGem ;
            XGem  = 0 ;
            Serial.println(" Send Gem to door ");
        }
        else if(Xnum==2||Xnum==12||Xnum==22||Xnum==32)
        {
            //เสียหิน
            if(XGem>0)
            {
                XGem = XGem - 1 ;
                Serial.println(" Lost one Gem");
                //next
            }
            else 
            {
                Serial.println("No Gem pass");
                //next
            }
        }
        else if(Xnum==3||Xnum==9||Xnum==13||Xnum==19||Xnum==23||Xnum==29||Xnum==33||Xnum==39)
        {
            //ได้หิน
            XGem = XGem + 1 ;
            Serial.println(" Get one Gem");
            //next
        }
        else if(Xnum==4||Xnum==8||Xnum==14||Xnum==18||Xnum==24||Xnum==28||Xnum==34||Xnum==38)
        {
            //สุ่มสกิล
            //กดปุ่ม
            roll = random(1,6);
            while (digitalRead(ButtonBlack)==0) {
            //จอบอกให้กดปุ่ม
            Serial.println("\t\tPush Button to play");
            }
            Serial.println(roll);
            if(roll == 1)   //Freeze
            {
                XFreze = (XFreze * 0) - 1 ;
                Serial.println("\t*Freze*");
                //next
            }
            else if (roll == 2)     //Toxic
            {
                XHp = XHp - 2 ;
                Serial.println("\t*Toxic*");
                //next
            }
            else if (roll == 3)     // Rewind
            {
                Serial.println("\t*Rewind*");
                if(Xnum == 4||Xnum == 14||Xnum == 24||Xnum == 34)   // GetGem
                {
                    XGem = XGem + 1 ;
                    Serial.println("\t*And get Gem*");
                    if(Xnum == 4)
                    {
                        Xnum = 3 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 13 ;
                        //next
                    }
                    else if(Xnum == 24)
                    {
                        Xnum = 23 ;
                        //next
                    }
                    else if(Xnum == 34)
                    {
                        Xnum = 33 ;
                        //next
                    }
                }
                else if(Xnum == 8||Xnum == 18)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 8)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 28||Xnum == 38)     // Damage
                {
                    Serial.println("\t*And Damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 28)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 38)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                
            }
            else if (roll == 4)     // Shield
            {
                XShield = 1 ;
                Serial.println("\t*Get Shield*");
                //next
            }
            else if (roll == 5)     //Triple
            {
                Serial.println("\t*Triple*");
                if(Xnum == 8||Xnum == 18||Xnum == 28||Xnum == 38)   // Door
                {
                    Serial.println("\t*And go to door*");
                    XDoor = XDoor+XGem ;
                    XGem  = 0 ;
                    if(Xnum == 8)
                    {
                        Xnum = 11 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 21 ;
                        //next
                    }
                    else if(Xnum == 28)
                    {
                        Xnum = 31 ;
                        //next
                    }
                    else if(Xnum == 38)
                    {
                        Xnum = 1 ;
                        //next
                    }
                }
                else if(Xnum == 4||Xnum == 14)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 4)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 24||Xnum == 34)     // Damage
                {
                    Serial.println("\t*And damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 24)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 34)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                //next
            }

            else if (roll == 6)     //Power shot
            {
                Serial.println("\t*Power Shot*");
                if(Xnum == 4||Xnum == 8)
                {
                    if(BossA == 1)
                    {
                        BossA = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 14||Xnum == 18)
                {
                    if(BossB == 1)
                    {
                        BossB = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");//next
                    }
                }
                if(Xnum == 24||Xnum == 28)
                {
                    if(BossC == 1)
                    {
                        BossC = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 34||Xnum == 38)
                {
                    if(BossD == 1)
                    {
                        BossD = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                       Serial.println("\tClear pass");
                        //next
                    }
                }
            }
        }
        else if(Xnum==5||Xnum==15||Xnum==27||Xnum==37)
        {
            //เสียเลือด 1
            XHp = XHp - 1 ;
            Serial.println("\tDamage -1 Hp");
            //next
        }
        else if(Xnum==6||Xnum==16||Xnum==26||Xnum==36)
        {
            //ขโมย
            if (XnextGem>0)
            {
            XnextGem = XnextGem - 1 ;
            XGem = XGem + 1 ;
            Serial.println("\tSteal Stone from Next player");
            //next 
            }
            else {
            Serial.println("\tPass");
            //next
            }
        }
        else if(Xnum==7||Xnum==17||Xnum==25||Xnum==35)
        {
            //ฮิล
            XHp = XHp + 1 ;
            Serial.println("\tGet 1 Hp");
            //next
        }
        else if(Xnum==10||Xnum==20||Xnum==30||Xnum==40)
        {
            //บอส
            if (Xnum == 10) 
            {
                if(BossA == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 20) 
            {
                if(BossB == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 30) 
            {
                if(BossC == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 40) 
            {
                if(BossD == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
 
        } 
next++;
Bnum=Xnum;
 BHp=XHp;
 BDoor=XDoor;
 BGem=XGem;
 BShield=XShield;
 BFreze=XFreze;
 Serial.print("\tYour position = ");
 Serial.print(Bnum);
 delay(1000);
    }   //Check Freze
 }while (next < 1);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void COperation(){
Xnum=0;
 XHp=0;
 XDoor=0;
 XGem=0;
 XShield=0;
 XFreze=CFreze;
 Xstart=0;
 
do {
XFreze = XFreze + 1 ;

if (XFreze<1) {
next++;
Serial.println("\tFreze hold for next round");

}

else if (XFreze>0) {
roll=random(1,6);

while (digitalRead(ButtonGreen)==0) {
//จอบอกให้กดปุ่ม 
Serial.println("\t\tPush Button to play");
}
Cnum+=roll;
 Xnum=Cnum;
 XHp=CHp;
 XDoor=CDoor;
 XGem=CGem;
 XShield=CShield;
 Xstart=Cstart;

while (Xnum>40) {

if(Xnum>40)
{
    Xnum = Xnum%40;
}
else {

}
}    
Serial.println(Xnum);
        if(Xnum==1||Xnum==11||Xnum==21||Xnum==31)
        {
            //เก็บหิน
            XDoor = XDoor+XGem ;
            XGem  = 0 ;
            Serial.println(" Send Gem to door ");
        }
        else if(Xnum==2||Xnum==12||Xnum==22||Xnum==32)
        {
            //เสียหิน
            if(XGem>0)
            {
                XGem = XGem - 1 ;
                Serial.println(" Lost one Gem");
                //next
            }
            else 
            {
                Serial.println("No Gem pass");
                //next
            }
        }
        else if(Xnum==3||Xnum==9||Xnum==13||Xnum==19||Xnum==23||Xnum==29||Xnum==33||Xnum==39)
        {
            //ได้หิน
            XGem = XGem + 1 ;
            Serial.println(" Get one Gem");
            //next
        }
        else if(Xnum==4||Xnum==8||Xnum==14||Xnum==18||Xnum==24||Xnum==28||Xnum==34||Xnum==38)
        {
            //สุ่มสกิล
            //กดปุ่ม
            roll = random(1,6);
            while (digitalRead(ButtonGreen)==0) {
            //จอบอกให้กดปุ่ม
            Serial.println("\t\tPush Button to play");
            }
            Serial.println(roll);
            if(roll == 1)   //Freeze
            {
                XFreze = (XFreze * 0) - 1 ;
                Serial.println("\t*Freze*");
                //next
            }
            else if (roll == 2)     //Toxic
            {
                XHp = XHp - 2 ;
                Serial.println("\t*Toxic*");
                //next
            }
            else if (roll == 3)     // Rewind
            {
                Serial.println("\t*Rewind*");
                if(Xnum == 4||Xnum == 14||Xnum == 24||Xnum == 34)   // GetGem
                {
                    XGem = XGem + 1 ;
                    Serial.println("\t*And get Gem*");
                    if(Xnum == 4)
                    {
                        Xnum = 3 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 13 ;
                        //next
                    }
                    else if(Xnum == 24)
                    {
                        Xnum = 23 ;
                        //next
                    }
                    else if(Xnum == 34)
                    {
                        Xnum = 33 ;
                        //next
                    }
                }
                else if(Xnum == 8||Xnum == 18)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 8)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 28||Xnum == 38)     // Damage
                {
                    Serial.println("\t*And Damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 28)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 38)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                
            }
            else if (roll == 4)     // Shield
            {
                XShield = 1 ;
                Serial.println("\t*Get Shield*");
                //next
            }
            else if (roll == 5)     //Triple
            {
                Serial.println("\t*Triple*");
                if(Xnum == 8||Xnum == 18||Xnum == 28||Xnum == 38)   // Door
                {
                    Serial.println("\t*And go to door*");
                    XDoor = XDoor+XGem ;
                    XGem  = 0 ;
                    if(Xnum == 8)
                    {
                        Xnum = 11 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 21 ;
                        //next
                    }
                    else if(Xnum == 28)
                    {
                        Xnum = 31 ;
                        //next
                    }
                    else if(Xnum == 38)
                    {
                        Xnum = 1 ;
                        //next
                    }
                }
                else if(Xnum == 4||Xnum == 14)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 4)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 24||Xnum == 34)     // Damage
                {
                    Serial.println("\t*And damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 24)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 34)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                //next
            }

            else if (roll == 6)     //Power shot
            {
                Serial.println("\t*Power Shot*");
                if(Xnum == 4||Xnum == 8)
                {
                    if(BossA == 1)
                    {
                        BossA = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 14||Xnum == 18)
                {
                    if(BossB == 1)
                    {
                        BossB = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");//next
                    }
                }
                if(Xnum == 24||Xnum == 28)
                {
                    if(BossC == 1)
                    {
                        BossC = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 34||Xnum == 38)
                {
                    if(BossD == 1)
                    {
                        BossD = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                       Serial.println("\tClear pass");
                        //next
                    }
                }
            }
        }
        else if(Xnum==5||Xnum==15||Xnum==27||Xnum==37)
        {
            //เสียเลือด 1
            XHp = XHp - 1 ;
            Serial.println("\tDamage -1 Hp");
            //next
        }
        else if(Xnum==6||Xnum==16||Xnum==26||Xnum==36)
        {
            //ขโมย
            if (XnextGem>0)
            {
            XnextGem = XnextGem - 1 ;
            XGem = XGem + 1 ;
            Serial.println("\tSteal Stone from Next player");
            //next 
            }
            else {
            Serial.println("\tPass");
            //next
            }
        }
        else if(Xnum==7||Xnum==17||Xnum==25||Xnum==35)
        {
            //ฮิล
            XHp = XHp + 1 ;
            Serial.println("\tGet 1 Hp");
            //next
        }
        else if(Xnum==10||Xnum==20||Xnum==30||Xnum==40)
        {
            //บอส
            if (Xnum == 10) 
            {
                if(BossA == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 20) 
            {
                if(BossB == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 30) 
            {
                if(BossC == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 40) 
            {
                if(BossD == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
 
        } 
next++;
Cnum=Xnum;
 CHp=XHp;
 CDoor=XDoor;
 CGem=XGem;
 CShield=XShield;
 CFreze=XFreze;
 Serial.print("\tYour position = ");
 Serial.print(Cnum);
 delay(1000);
    }   //Check Freze
 }while (next < 1);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void DOperation(){
Xnum=0;
 XHp=0;
 XDoor=0;
 XGem=0;
 XShield=0;
 XFreze=DFreze;
 Xstart=0;
 
do {
XFreze = XFreze + 1 ;

if (XFreze<1) {
next++;
Serial.println("\tFreze hold for next round");

}

else if (XFreze>0) {
roll=random(1,6);

while (digitalRead(ButtonRed)==0) {
//จอบอกให้กดปุ่ม 
Serial.println("\t\tPush Button to play");
}
Dnum+=roll;
 Xnum=Dnum;
 XHp=DHp;
 XDoor=DDoor;
 XGem=DGem;
 XShield=DShield;
 Xstart=Dstart;

while (Xnum>40) {

if(Xnum>40)
{
    Xnum = Xnum%40;
}
else {

}
}    
Serial.println(Xnum);
        if(Xnum==1||Xnum==11||Xnum==21||Xnum==31)
        {
            //เก็บหิน
            XDoor = XDoor+XGem ;
            XGem  = 0 ;
            Serial.println(" Send Gem to door ");
        }
        else if(Xnum==2||Xnum==12||Xnum==22||Xnum==32)
        {
            //เสียหิน
            if(XGem>0)
            {
                XGem = XGem - 1 ;
                Serial.println(" Lost one Gem");
                //next
            }
            else 
            {
                Serial.println("No Gem pass");
                //next
            }
        }
        else if(Xnum==3||Xnum==9||Xnum==13||Xnum==19||Xnum==23||Xnum==29||Xnum==33||Xnum==39)
        {
            //ได้หิน
            XGem = XGem + 1 ;
            Serial.println(" Get one Gem");
            //next
        }
        else if(Xnum==4||Xnum==8||Xnum==14||Xnum==18||Xnum==24||Xnum==28||Xnum==34||Xnum==38)
        {
            //สุ่มสกิล
            //กดปุ่ม
            roll = random(1,6);
            while (digitalRead(ButtonRed)==0) {
            //จอบอกให้กดปุ่ม
            Serial.println("\t\tPush Button to play");
            }
            Serial.println(roll);
            if(roll == 1)   //Freeze
            {
                XFreze = (XFreze * 0) - 1 ;
                Serial.println("\t*Freze*");
                //next
            }
            else if (roll == 2)     //Toxic
            {
                XHp = XHp - 2 ;
                Serial.println("\t*Toxic*");
                //next
            }
            else if (roll == 3)     // Rewind
            {
                Serial.println("\t*Rewind*");
                if(Xnum == 4||Xnum == 14||Xnum == 24||Xnum == 34)   // GetGem
                {
                    XGem = XGem + 1 ;
                    Serial.println("\t*And get Gem*");
                    if(Xnum == 4)
                    {
                        Xnum = 3 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 13 ;
                        //next
                    }
                    else if(Xnum == 24)
                    {
                        Xnum = 23 ;
                        //next
                    }
                    else if(Xnum == 34)
                    {
                        Xnum = 33 ;
                        //next
                    }
                }
                else if(Xnum == 8||Xnum == 18)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 8)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 28||Xnum == 38)     // Damage
                {
                    Serial.println("\t*And Damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 28)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 38)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                
            }
            else if (roll == 4)     // Shield
            {
                XShield = 1 ;
                Serial.println("\t*Get Shield*");
                //next
            }
            else if (roll == 5)     //Triple
            {
                Serial.println("\t*Triple*");
                if(Xnum == 8||Xnum == 18||Xnum == 28||Xnum == 38)   // Door
                {
                    Serial.println("\t*And go to door*");
                    XDoor = XDoor+XGem ;
                    XGem  = 0 ;
                    if(Xnum == 8)
                    {
                        Xnum = 11 ;
                        //next
                    }
                    else if(Xnum == 18)
                    {
                        Xnum = 21 ;
                        //next
                    }
                    else if(Xnum == 28)
                    {
                        Xnum = 31 ;
                        //next
                    }
                    else if(Xnum == 38)
                    {
                        Xnum = 1 ;
                        //next
                    }
                }
                else if(Xnum == 4||Xnum == 14)      // Heal
                {
                    Serial.println("\t*And Heal*");
                    XHp = XHp + 1 ;
                    if(Xnum == 4)
                    {
                        Xnum = 7 ;
                        //next
                    }
                    else if(Xnum == 14)
                    {
                        Xnum = 17 ;
                        //next
                    }
                }
                else if(Xnum == 24||Xnum == 34)     // Damage
                {
                    Serial.println("\t*And damage*");
                    XHp = XHp - 1 ;
                    if(Xnum == 24)
                    {
                        Xnum = 27 ;
                        //next
                    }
                else if(Xnum == 34)
                    {
                        Xnum = 37 ;
                        //next
                    }
                }
                //next
            }

            else if (roll == 6)     //Power shot
            {
                Serial.println("\t*Power Shot*");
                if(Xnum == 4||Xnum == 8)
                {
                    if(BossA == 1)
                    {
                        BossA = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 14||Xnum == 18)
                {
                    if(BossB == 1)
                    {
                        BossB = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss Die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");//next
                    }
                }
                if(Xnum == 24||Xnum == 28)
                {
                    if(BossC == 1)
                    {
                        BossC = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                        Serial.println("\tClear pass");
                        //next
                    }
                }
                if(Xnum == 34||Xnum == 38)
                {
                    if(BossD == 1)
                    {
                        BossD = 0 ;
                        XGem = XGem + 1 ;
                        Xnum = Xstart ;
                        XDoor = XDoor + XGem ;
                        XGem = 0 ;
                        Serial.println("\t*Boss die*");
                        //next
                    }
                    else
                    {
                       Serial.println("\tClear pass");
                        //next
                    }
                }
            }
        }
        else if(Xnum==5||Xnum==15||Xnum==27||Xnum==37)
        {
            //เสียเลือด 1
            XHp = XHp - 1 ;
            Serial.println("\tDamage -1 Hp");
            //next
        }
        else if(Xnum==6||Xnum==16||Xnum==26||Xnum==36)
        {
            //ขโมย
            if (XnextGem>0)
            {
            XnextGem = XnextGem - 1 ;
            XGem = XGem + 1 ;
            Serial.println("\tSteal Stone from Next player");
            //next 
            }
            else {
            Serial.println("\tPass");
            //next
            }
        }
        else if(Xnum==7||Xnum==17||Xnum==25||Xnum==35)
        {
            //ฮิล
            XHp = XHp + 1 ;
            Serial.println("\tGet 1 Hp");
            //next
        }
        else if(Xnum==10||Xnum==20||Xnum==30||Xnum==40)
        {
            //บอส
            if (Xnum == 10) 
            {
                if(BossA == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 20) 
            {
                if(BossB == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 30) 
            {
                if(BossC == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
            else if (Xnum == 40) 
            {
                if(BossD == 1)
                {
                    if(XShield == 1)
                    {
                        XShield = 0 ;
                        Serial.println("\t*Block from boss*");
                        //next
                    }
                    else
                    {
                        XHp = XHp - 3 ;
                        Serial.println("\tBoss hit u 3 hp");
                        //next
                    }
                }
            }
 
        } 
next++;
Dnum=Xnum;
 DHp=XHp;
 DDoor=XDoor;
 DGem=XGem;
 DShield=XShield;
 DFreze=XFreze;
 Serial.print("\tYour position = ");
 Serial.print(Dnum);
 delay(1000);
    }   //Check Freze
 }while (next < 1);
}
