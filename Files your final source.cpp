#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;
void edit();
void showc();
void createfolder();
void renamef();
void deletef();
void cutf();
int copyf();
int userchoice;
string filename,filepath,filepathedit,data,filepathshowc;
char echoice,savechoice,folderpath[1000],filepathrename[1000],filenamenew[1000];

void Menu()
{
    cout<<"\n\t\t\t\t\t\t<<Main Menu>>";
    cout<<"\n\n\t**In this program enter spaces with '_'**";
    cout<<"\n\n\n0: Exit\t\t1: Create file\t\t2: Edit\t\t3: Show content\t\t4: Copy\t\t5: Cut\t\t6: Delete\t\t7: Create Folder\t\t8: Rename";
    cout<<"\n\nWhat to do?(enter your choice number) :";
    cin>>userchoice;
}

void fc(string fp , string fn)
{
    ofstream mfile(fp + "\\"+ fn + ".txt");
    if(!mfile)
        cout<<"\n\nError in creating file!\n\n";
    else if(mfile)
        cout<<"\n\nFile created successfully!\n\n";
    mfile.close();
}

void createfile()
{
    cout<<"\nName of your file:";
    cin>>filename;
    cout<<"\nEnter the path of file:";
    cin>>filepath;
    cout<<filepath;
    fc(filepath,filename);
}


int main()
{

    while(1)
    {
        Menu();
        if(userchoice==1)
            createfile();
        else if(userchoice==2)
            edit();
        else if(userchoice==3)
            showc();
        else if(userchoice==4)
            copyf();
        else if(userchoice==5)
            cutf();
        else if(userchoice==6)
            deletef();
        else if(userchoice==7)
            createfolder();
        else if(userchoice==8)
            renamef();
        else if(userchoice==0)
            break;
            //exit(0);
        else
            cout<<"\n\nWrong input!\n\n";
    }
    cout<<"\n\n\n\n\nGoodbye!\n\n\n\n\n";
    //getch();
    return 0;
}

void edit()
{
    cout<<"\nEnter your file path:";
    cin>>filepathedit;
    ifstream editfile(filepathedit+".txt" , ios::app);
    if(!editfile)
        cout<<"\nWrong path!";
    else{
        cout<<"\nDo you want to add(a) something or delete(d)?";
        cin>>echoice;
        if(echoice == 'a')
        {
            cout<<"\nEnter your data:";
            cin>>data;
            cout<<"Do you want to save data?(y,n)";
            cin>>savechoice;
            if(savechoice=='y'){
                ofstream editfile(filepathedit+".txt" , ios::app);
                editfile<<data;
                editfile.close();
            }
        }
    }
    editfile.close();
}
void showc()
{
    cout<<"\nEnter your file path:";
    cin>>filepathshowc;
    ifstream rf;
    rf.open(filepathshowc + ".txt" , ios::app);
    if(!rf) {
        cout << "\nWrong path!";
    }
    else {
        string fc;
        rf >> fc;
        cout << "\n\t\t\t\tYour file content\n";
        cout << "-------------------------------------------------\n\n";
        cout << fc << "\n\n";
        cout << "-------------------------------------------------\n\n";
    }
    rf.close();
}
void createfolder()
{
    cout<<"\nEnter your folder path in this format\t(C:\\Test\\your folder name) :";
    cin>>folderpath;
    mkdir(folderpath);
    cout<<"\n\tDone!";
}
void renamef()
{
    cout<<"\nEnter your file path with format:";
    cin>>filepathrename;
    cout<<"\nEnter your new name beside path\t(C:\\test\\new name.format) :";
    cin>>filenamenew;
    int var = rename(filepathrename , filenamenew);
    if(var==0)
        cout<<"\nFile name changed successfully!";
    else
        cout<<"\nFailed!";
}
void deletef()
{
    char filepathdel[1000];
    cout<<"\nEnter your file path + its format:";
    cin>>filepathdel;
    if(!remove(filepathdel))
        cout<<"\nFailed!";
    else
        cout<<"\nFile deleted successfully!";
}
int copyf()
{
    char line[100],srcfile[20],destfile[20];
    cout<<"\nEnter your source file path with format:"<<endl;
    cin>>srcfile;
    cout<<"\nEnter your destination file path with format:"<<endl;
    cin>>destfile;
    ofstream fout;
    fout.open(destfile,ios::app);
    ifstream fin;
    fin.open(srcfile,ios::app);


    while(fin.eof()==0)
    {
        fin.getline(line,sizeof(line));
        fout<<line<<"\n";
    }
    cout<<"\nFile copied successfuly.....\n";
    fin.close();
    fout.close();
    return 0;
}

void cutf()
{
    string fcut,srcfilec,destfilec;
    char srcfilecs[1000];
    cout<<"\nEnter your source file path with format:";
    //cin>>srcfilec;
    cin>>srcfilecs;
    cout<<"\nEnter your destination file path with format:";
    cin>>destfilec;
    ifstream fin;
    fin.open(srcfilecs,ios::in | ios::app);
    if(!fin)
    {
        cout<<"\nError in opening"<<srcfilec<<"file...\n";
    }
    else {
        ofstream fout;
        fout.open(destfilec,ios::out);
        fin>>fcut;
        fout<<fcut;
        fout.close();
    }
    fin.close();
    if(remove(srcfilecs)==0)
        cout << "\nFile cut successfully.....\n";
}
