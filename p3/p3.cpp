#include "sdt.h"

void print_in_binary(uint8_t byte)
{
    for(unsigned char i=0; i<8; i++)
    {
        if ((byte<<i) &0b10000000)
            cout << '1';
        else
            cout << '0';
    }
}void print(int a)
{
    switch (a)
    {
    case 10: cout <<'A';
     break;
    case 11: cout <<'B';
     break;
    case 12: cout <<'C';
     break;
    case 13: cout <<'D';
     break;
    case 14: cout <<'E';
     break;
    case 15: cout <<'F';
     break;
     default: cout<<a;
    }
}
void print_in_hex(uint8_t byte)
{  int a1 = byte&0b00001111;
  int a2 = (byte>>4)&0b00001111;
  print(a2);
  print(a1);
}
void print_in_binaryAll(const void* data, size_t size)
{
    uint8_t* one=(uint8_t*)data;
    for(int i=0; i<size; i++)
    {
        print_in_binary(*one);
        cout<<' ';
        one+=1;
    }
}

void print_in_hexAll(const void* data, size_t size)
{
    uint8_t* one=(uint8_t*)data;
    for(int i=0; i<size; i++)
    {
        print_in_hex(*one);
        cout<<' ';
        one+=1;
    }
}

struct Student
{
    char Name [15];
    unsigned int Year;
    unsigned int SredBal;
    short Pol : 1;
    unsigned short Course;
    Student* Starosta;
};

main()
{

Student stud[3]=
    {
        {"Arina", 2013, 4, 0, 2, nullptr},
        {"Dima", 2013, 5, 1, 2, &stud[0]},
        {"Nikita",2013, 5, 1, 2, &stud[1]}
    };

    cout << "Address massiva : " << &stud << endl;
    cout << "Razmer massiva stud : " << sizeof(stud) << endl;
    cout << "\nStud \t\t Address stud \t\t Size" << endl;


for (int i = 0; i < 3; ++i)
    {
        cout <<stud[i].Name<<":"<< i <<"\t\t"<<&stud[i]<<"\t\t"<<sizeof(stud[i]) <<endl;
    }

    cout <<"\nField Name:";
    cout <<"\nAddress stud[1]: " << &stud[1].Name;
    cout <<"\nOffset stud[1]: " <<offsetof(struct Student, Name);
    cout <<"\nSize stud[1]: " <<sizeof(stud[1].Name);
    cout <<"\nIn binary: ";
    print_in_binaryAll(&stud[1].Name, sizeof(stud[1].Name));
    cout <<"\nIn hex: ";
    print_in_hexAll(&stud[1].Name, sizeof(stud[1].Name));

    cout <<"\n\nField Year:";
    cout <<"\nAddress stud[1]: " <<&stud[1].Year;
    cout <<"\nOffset stud[1]: " <<offsetof(struct Student, Year);
    cout <<"\nSize stud[1]: " <<sizeof(stud[1].Year);
    cout <<"\nIn binary: ";
    print_in_binaryAll(&stud[1].Year, sizeof(stud[1].Year));
    cout <<"\nIn hex: ";
    print_in_hexAll(&stud[1].Year, sizeof(stud[1].Year));

    cout <<"\n\nField SredBal:";
    cout <<"\nAddress stud[1]: " <<&stud[1].SredBal;
    cout <<"\nOffset stud[1]: " <<offsetof(struct Student, SredBal);
    cout <<"\nSize stud[1]: " <<sizeof(stud[1].SredBal);
    cout <<"\nIn binary: ";
    print_in_binaryAll(&stud[1].SredBal, sizeof(stud[1].SredBal));
    cout <<"\nIn hex: ";
    print_in_hexAll(&stud[1].SredBal, sizeof(stud[1].SredBal));

    cout <<"\n\nField Course:";
    cout <<"\nAddress stud[1]: " <<&stud[1].Course;
    cout <<"\nOffset stud[1]: " <<offsetof(struct Student, Course);
    cout <<"\nSize stud[1]: " <<sizeof(stud[1].Course);
    cout <<"\nIn binary: ";
    print_in_binaryAll(&stud[1].Course, sizeof(stud[1].Course));
    cout <<"\nIn hex: ";;
    print_in_hexAll(&stud[1].Course, sizeof(stud[1].Course));

    cout <<"\n\nField Starosta:";
    cout <<"\nAddress stud[1]: " <<stud[1].Starosta;
    cout <<"\nOffset stud[1]: " <<offsetof(struct Student, Starosta);
    cout <<"\nSize stud[1]: " <<sizeof(stud[1].Starosta);
    cout <<"\nIn binary: ";
    print_in_binaryAll(stud[1].Starosta, sizeof(stud[1].Starosta));
    cout <<"\nIn hex: ";
    print_in_hexAll(stud[1].Starosta, sizeof(stud[1].Starosta));

    cout << endl;
    cout <<"\n| Name | Year  |    MeanS   |  Curs  | Starosta\n";
    for(int i = 0; i < 3; ++i)
    {
        cout << i << endl<<endl;
        print_in_hexAll(&stud[i].Name, sizeof(stud[i].Name));
        cout << endl ;
        print_in_hexAll(&stud[i].Year, sizeof(stud[i].Year));
        cout << endl ;
        print_in_hexAll(&stud[i].SredBal, sizeof(stud[i].SredBal));
        cout << endl ;
        print_in_hexAll(&stud[i].Course, sizeof(stud[i].Course));
        cout << endl ;
        print_in_hexAll(&stud[i].Starosta, sizeof(stud[i].Starosta));
        cout << endl<<endl ;
    }
}
