#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;

#ifdef WIN32
	#include <winsock2.h>
	#include <windows.h>
	
	HWND hwnd=FindWindow("ConsoleWindowClass",NULL);
	
	const int maxn = 1001;
	const int maxm = 1001;
	
	int main(int argc, char** argv)
	{
		puts("==========================PROGRAM SETTINGS===========================\n");
		char totstr[maxm*100]="\0";
		char perstr[maxn][maxm]={"\0"};
		cout<<"arg count <- "<<argc-1<<"\n";
		cout<<"argv value(s):\n{\n";
		if(argc<2)
		{
			cout<<"\t[PGDebugger::NONE]\n";
		}
		else if(argc>1)
		{
			for(int i=2;i<=argc;i++)
			{
				strcpy(perstr[i],*((i-1)+argv));
				if(i!=2)
				{
					strcat(totstr," ");
				}
				strcat(totstr,perstr[i]);
				cout<<"\t["<<i-1<<"] <- \t";
				puts(perstr[i]);
			}
		}
		cout<<"}\n";
		if(argc>=2)
		{
			puts("Console-Command:");
			cout<<"PGDebugger.exe ";
			puts(totstr);
		}
		if(argc>1)
		{
			register int f;
			char temp[maxm]="\0";
			strcpy(temp,*(1+argv));
			if(temp[strlen(temp)-1]=='e')
			{
				if(temp[strlen(temp)-2]=='x')
				{
					if(temp[strlen(temp)-3]=='e')
					{
						if(temp[strlen(temp)-4]=='.')
						{
							system("pause");
							puts("=========================RUNNING EXE PROGRAM==========================\n");
							STARTUPINFOA si;
							PROCESS_INFORMATION pi;
							 
							ZeroMemory(&pi,sizeof(pi));
							ZeroMemory(&si,sizeof(si));
							si.cb=sizeof(STARTUPINFOA);
							BOOL working=::CreateProcess(NULL,totstr,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS ,NULL,NULL,&si,&pi);
							if (working==0)
							{
								DWORD error=GetLastError();
								cout << "CreateProcess Error : "<<error<<endl;
							}
							WaitForSingleObject(pi.hProcess,INFINITE);
							unsigned long Result;
							GetExitCodeProcess(pi.hProcess,&Result);
							cout << "Exit Code : "<<Result<<endl;
							exit(0);
						}
					}
				}
			}
		}
		cout<<"\nNO-NEED EXECUTE(NOT EXE FILE).\n";
		system("pause");
		return 0;
	}
#endif
#ifdef Llinux
	void Xsystem(string command)
	{
		pid_t status=system(command.c_str());
		if(status==-1 or !WIFEXITED(status) or WEXITSTATUS(status)!=0)
		{
			cout<<"Excute Failed!"<<'\n';
		}
		else
		{
			printf("---------------------------\n");
			printf("progress exited with %d or 0x%x",WEXITSTATUS(status),status);
		}
	}
	int main(int argc, char const *argv[])
	{
		if(argc==1)
		{
			printf("-------------Usage-------------\n");
			printf("./PGDebugger program_need_to_run\n");
			printf("-------------Usage-------------\n");
		}
		else if(argc>2)
		{
			printf("Too many args!\n");
		}
		else
		{
			string tmp="./";
			tmp+=argv[1];
		}
		
		return 0;
	}
#endif
