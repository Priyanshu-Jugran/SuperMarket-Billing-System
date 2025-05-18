//_____________header files used in the project_____________________________________________

#include<iostream>
#include<fstream> 
#include<windows.h> 
using namespace std;

//______________declaration of functions used in project____________________________________________________________________


int color(int);//function to change color of text in console
void intro();// function for introduction of project


//_______________class used in the project__________________________________________________

class shop 
{
private:
int code;
string name;
float price;

public:
void main_menu();// function for main menu
void administrator_menu();// function for administrator menu
void buyer_menu();// function for buyer menu
void add();// function to add products in product list
void rem();// function to remove products from the list
void mod();// function to modify products in the list
void get_list();// function to print available product list
void receipt();// function to generate receipt for buyer
};


//_________Defination of the member functions____________________________________________________________

void shop :: main_menu(){
m:
system("cls");
int choice;
string email;
string password;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"|                                |"<<endl;
cout<<"|     SUPER MARKET MAIN MENU     |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"| 1) Login as buyer              |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 2) Login as administrator      |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 3) To exit                     |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<endl<<"Enter your choice: ";
color(3);
cin>>choice;
switch(choice){
    case 1:
    buyer_menu();
    break;

    case 2:
    system("cls");
    color(1);
    cout<<"To continue as an administrator...\n\n";
    cout<<" Please enter your email: ";
    color(3);
    cin>>email;
    color(1);
    cout<<" Please enter your password: ";
    color(3);
    cin>>password;
    if(email == "pj@email" && password == "pj@123")
    administrator_menu();
    else{
        system("cls");
        color(4);
    cout<<"Invalid email or password!\n\n";
    color(1);
    system("pause");
    }
    break;

    case 3:
    system("cls");
    color(1);
    cout<<"  Thankyou! for using 'SUPER MARKET BILLING SYSTEM'\n\n";
    system("pause");
    system("cls");
    exit(0);
    break;

    default:
    system("cls");
    color(4);
    cout<<" Invalid choice! please try again..\n\n";
    color(1);
    system("pause");
    break;
}
goto m;
}


void shop :: administrator_menu(){
m:
system("cls");
int choice;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"|                                |"<<endl;
cout<<"|       ADMINISTRATOR MENU       |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"| 1) Add a product               |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 2) Remove a product            |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 3) Modify a product            |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 4) Back to main menu           |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<endl<<"Enter your choice: ";
color(3);
cin >> choice;
switch(choice){
    case 1:
    add();
    break;

    case 2:
    rem();
    break;

    case 3:
    mod();
    break;

    case 4:
    main_menu();
    break;

    default:
    system("cls");
    color(4);
    cout<<" Invalid choice! please try again..\n\n";
    color(1);
    system("pause");
    break;

}
goto m;
}


void shop :: buyer_menu(){
m:
system("cls");
int choice;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"|                                |"<<endl;
cout<<"|           BUYER MENU           |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<" ________________________________ "<<endl;
color(3);
cout<<"| 1) Buy a product               |"<<endl;
cout<<"|                                |"<<endl;
cout<<"| 2) Back to main menu           |"<<endl;
cout<<"|";
color(1);
cout<<"________________________________";
color(3);
cout<<"|"<<endl;
color(1);
cout<<endl<<"Enter your choice: ";
color(3);
cin >> choice;
switch(choice){
    case 1:
    receipt();
    break;

    case 2:
    main_menu();
    break;

    default:
    system("cls");
    color(4);
    cout<<" Invalid choice! please try again..\n\n";
    color(1);
    system("pause");
    break;
}
goto m;
}


void shop :: add(){
system("cls");
fstream data;
int flag = 0;
int c;
string n;
float p;
data.open("list.txt",ios::in);
if(data)
get_list();
color(1);
cout<<"To add a product...\n\n";
cout<<" Please enter the product code: ";
color(3);
cin>>code;
color(1);
cout<<" Please enter the product name: ";
color(3);
cin>>name;
color(1);
cout<<" Please enter the price: ";
color(3);
cin>>price;

if(!data){
data.open("list.txt",ios::app|ios::out);
data<<code<<" "<<name<<" "<<price<<endl;
data.close();
}

else{
data>>c>>n>>p;
while(!data.eof()){
    if(c==code){
    flag = 1;
    break;
    }
    data>>c>>n>>p;
}
data.close();

if(flag==1){
    system("cls");
    color(4);
    cout<<" Record already inserted!\n\n";
    color(1);
    system("pause");
    return;
}

data.open("list.txt",ios::app|ios::out);
data<<code<<" "<<name<<" "<<price<<endl;
data.close();
}
system("cls");
get_list();
color(2);
cout<<" Record inserted!\n\n";
color(1);
system("pause");
}


void shop :: rem(){
system("cls");
fstream data,data2;
int key;
int flag=0;
data.open("list.txt",ios::in);
if(!data){
    color(4);
    cout<<" Record is empty!\n\n";
    color(1);
    system("pause");
    return;
}
get_list();
color(1);
cout<<"To remove a product...\n\n";
cout<<" Please enter the product code: ";
color(3);
cin>>key;

data2.open("list2.txt",ios::app|ios::out);
data>>code>>name>>price;
while(!data.eof()){
    if(code==key){
        flag=1;
    }
    else{
        data2<<code<<" "<<name<<" "<<price<<endl;
    }
    data>>code>>name>>price;
}
data.close();
data2.close();
system("cls");
if(flag==0){
remove("list2.txt");
color(4);
cout<<" No record found!\n\n";
}
else{
    remove("list.txt");
    rename("list2.txt","list.txt");
    get_list();
    color(2);
    cout<<" Product removed successfully!\n\n";
}
color(1);
system("pause");
}


void shop:: mod(){
system("cls");
fstream data,data2;
int key;
int c;
string n;
float p;
int flag=0;
data.open("list.txt",ios::in);
if(!data){
    color(4);
    cout<<" Record is empty!\n\n";
    color(1);
    system("pause");
    return;
}
get_list();
color(1);
cout<<"To modify a product...\n\n";
cout<<" Please enter the product code: ";
color(3);
cin>>key;

data2.open("list2.txt",ios::app|ios::out);
data>>code>>name>>price;
while(!data.eof()){
    if(key==code){
        system("cls");
        color(1);
        cout<<"Please enter the new product code: ";
        color(3);
        cin>>c;
        color(1);
        cout<<"\nPlease enter the name of new product: ";
        color(3);
        cin>>n;
        color(1);
        cout<<"\nPlease enter the price of new product: ";
        color(3);
        cin>>p;
        flag=1;
        data2<<c<<" "<<n<<" "<<p<<endl;
    }
    else{
        data2<<code<<" "<<name<<" "<<price<<endl;
    }
    data>>code>>name>>price;
}
data.close();
data2.close();
system("cls");
if(flag==0){
remove("list2.txt");
color(4);
cout<<" No record found!\n\n";
}
else{
    remove("list.txt");
    rename("list2.txt","list.txt");
    get_list();
    color(2);
    cout<<" Product modified successfully!\n\n";
}
color(1);
system("pause");
}


void shop :: get_list(){
fstream data;
data.open("list.txt",ios::in);
color(1);
cout<<"            PRODUCT   LIST             "<<endl;
cout<<"_______________________________________"<<endl;
cout<<" P.Code\t\tP.Name\t\tP.Price"<<endl;
cout<<"_______________________________________"<<endl;
color(3);
data>>code>>name>>price;
while(!data.eof()){
cout<<" "<<code<<"\t\t"<<name<<"\t\t"<<price<<endl;
data>>code>>name>>price;
}
data.close();
cout<<"_______________________________________"<<endl;
}


void shop :: receipt(){
fstream data;
int arrc[100];
int arrq[100];
int c=0;
int choice;
float amount=0;
float total=0;

data.open("list.txt",ios::in);
if(!data){
    data.close();
    system("cls");
    color(4);
    cout<<" No product is available!\n\n";
    color(1);
    system("pause");
    return;
}
data.close();
do{
m:
system("cls");
get_list();
cout<<endl;
color(1);
cout<<" Please place the order...\n\n";
cout<<"Enter the product code: ";
color(3);
cin>>arrc[c];
color(1);
cout<<"Enter the quantity: ";
color(3);
cin>>arrq[c];

for(int i=0;i<c;i++){
    if(arrc[c]==arrc[i]){
        system("cls");
        color(4);
        cout<<" Duplicate product code! Please try again...\n\n";
        color(1);
        system("pause");
        goto m;
    }   
}
c++;
system("cls");
color(2);
cout<<"Product added to cart!\n\n";
color(1);
h:
cout<<" Do you want to buy another product?\n If yes press '1' otherwise press '2'..\n\n";
cout<<"Enter your choice: ";
cin>>choice;
if(choice!=1 && choice!=2){
    system("cls");
    color(4);
    cout<<" Invalid choice!\n\n";
    color(1);
    system("pause");
    system("cls");
    goto h;
}
}while(choice==1);
system("cls");
color(1);
cout<<"                        RECEIPT                          "<<endl;
cout<<"_________________________________________________________"<<endl;
cout<<"P.Code\t\tP.Name\t\tQuantity\tAmount"<<endl;
cout<<"_________________________________________________________"<<endl;

color(3);
for(int i=0;i<c;i++){
    data.open("list.txt",ios::in);
    data>>code>>name>>price;
    while(!data.eof()){
        if(code==arrc[i]){
            amount = price*arrq[i];
            total = total + amount;
            cout<<code<<"\t\t"<<name<<"\t\t"<<arrq[i]<<"\t\t"<<amount<<endl;
        }
        data>>code>>name>>price;
    }
    data.close();
}
color(1);
cout<<"_________________________________________________________"<<endl;
cout<<"                   TOTAL AMOUNT : "<<total<<endl<<endl;
color(3);
system("pause");
}


//____________________main function_____________________________________________________  

int main(){
intro();
shop s;
s.main_menu();
return 0;
}


//_______defination of functions declared above__________________________________________

int color(int c){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h,c);
}

void intro(){
system("cls");
color(1);
cout<<" _______________________________ "<<endl;
cout<<"||_____________________________||"<<endl;
color(3);
cout<<"||                             ||"<<endl;
cout<<"|| SUPER MARKET BILLING SYSTEM ||"<<endl;
cout<<"||                             ||"<<endl;
color(1);
cout<<"||_____________________________||"<<endl;
cout<<"||_____________________________||"<<endl;
color(3);
cout<<"||           Made by           ||"<<endl;
cout<<"||      'Priyanshu Jugran'     ||"<<endl;
color(1);
cout<<"||_____________________________||"<<endl;
cout<<"||_____________________________||"<<endl;
cout<<endl;
color(1);
system("pause");
}


//__________________end of project_____________________________________________________