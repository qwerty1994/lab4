#include "sdt.h"

int proverka(char* name)
{
    //проверка на символы *,",<,>,?,|
    if (strpbrk(name,"*<>?|\"")!= 0) //strpbrk - cканирует строку name на присутствие символов из второй строки
    {
        cout <<"Unknown symbol (*<>?|\""<<endl;
        return 1;
    }
    //проверка на :
    if (strpbrk(name,":") != 0) //сканирует на наличие :
        if (strchr(name, ':') == &name[1] && strrchr(name, ':') == &name[1])
        {
            if(!isalpha(name[0]))
            {
            cout <<"Before : not a letter"<<endl;
                return 1;
            }
            if(name[2]!= '\\')
            {
                cout <<"After : not \\"<<endl;
                return 1;
            }
        }
        else
        {
            cout<<"Wrong applying the symbol : "<<endl;
            return 1;
        }
//проверка на расширение
    strrev(name); //strrev(char *s) - переписывает символы в строке в обратном порядке
    if ( strncmp(name, "txt.", 4 ) != 0 && strncmp( name, "TXT.", 4 ) != 0) //strncmp-сравнивает строки
    {
        cout<<"Wrong format! (.txt or .TXT)"<<endl;
        return 1;
    }
    strrev(name);
    return 0;
}

main()
{
char file_name[20];
    int p = 1;
    while (p)
    {
        cout <<"Enter a file name with text (.txt):  ";
        cin >> file_name;
        p = proverka(file_name);
    }

FILE * file = fopen(file_name, "a+");
    fseek(file,0,SEEK_END);
    int size_ = ftell(file);
    fseek(file,0,SEEK_SET);
    char *mass = new char[ size_ +1 ];
    memset(mass, 0, size_ +1);
    unsigned long result = fread(mass, sizeof(char), size_, file);
    if (ferror(file))
    {
        cout<<"File error\n";
        exit (1);
    }
    cout <<"\nThe contents of the file:"<<endl;
    puts(mass);

    cout <<"\nEnter a search string:  ";
    char str[20];
    cin >>str;

    char *cp = (char *) mass;
    char *s1, *s2;
    while(*cp)
    {
        s1 = cp;
        s2 = (char *) str;
        while ( *s1 && *s2 && !(*s1-*s2) )
            s1++, s2++;
        if (!*s2)
            cout<<"Position of the string: "<<(cp-mass+1)<<endl;
        cp++;
    }


    int * pred=new int [20];
    int n=0;
    pred[0]=-1;
    for(int i=0; i<size_; ++i)
            if(mass[i] == '.' || mass[i] == '?' || mass[i] == '!')
            {
                ++n;
                pred[n]=i;
            }
    cout <<"\nThe number of proposals: "<<n<<endl;
    char ** PRED=new char*[n];
        for(int i=0; i<n; ++i)
        {
            fseek(file, pred[i]+1,SEEK_SET);
            char *mass1 = new char[pred[i+1]]; //выделение памяти
            fread(mass1,sizeof(char),pred[i+1],file);
            char *mass2 = new char[pred[i+1]];
            PRED[i]= strncpy(mass2, mass1, (pred[i+1]-pred[i])*sizeof(char));
            delete [] mass1; //освобождение выделенной памяти
        }
        fclose (file);
        cout<<endl;
        for(int i=0; i<n; ++i)
           cout<<i+1<<" proposal ("<<strlen(PRED[i])<<") : "<<PRED[i]<<endl;;


    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strlen(PRED[j]) > strlen(PRED[j+1]))
            swap(PRED[j],PRED[j+1]);
        }
    }
    cout<<"\nSorting proposal:\n";
    for(int i=0; i<n; ++i)
    cout<<i+1<<" proposal ("<<strlen(PRED[i])<<") : "<<PRED[i]<<endl;


    char file2_name[20];
    p = 1;
    while (p)
    {
        cout << "\nEnter a new file name for the record (.txt)\n";
        cin >> file2_name;
        p = proverka(file2_name);
        cout <<endl;
    }
    FILE * file2 = fopen(file2_name, "a+");
    fseek(file2,0,SEEK_SET);  //положение в начало файла
    for(int i=0; i<n; ++i)
        fputs(PRED[i], file2);
        fclose (file2);

    delete [] mass;
    delete [] pred;
    delete [] cp;
    delete s1;
    delete s2;

}
