#include <stdio.h>
#include <process.h> 
#include <windows.h> 
#include <time.h>

using namespace std;

void delay_ms(int maxDelay)  //specify delay in ms
{
     clock_t t1, t2;
    t1 = clock();
    t2 = clock();
    while(t2-t1<maxDelay) // in ms
    {             
     t2 = clock();
     }
}

void sendMsgToNotepad(HWND hwndEdit) // set the message to appear in notepad
{
     SendMessage(hwndEdit,WM_SETTEXT,0,(LPARAM)"test");
     delay_ms(400);
     SendMessage(hwndEdit,WM_SETTEXT,0,(LPARAM)"testtest");
     delay_ms(300);
     SendMessage(hwndEdit,WM_SETTEXT,0,(LPARAM)"testtesttest");
 
}     

void setNotepadTitle(HWND hwndNotepad)   // set window title here
{
  SetWindowText(hwndNotepad, (LPSTR) "Untitled 1");
  delay_ms(2000);
  SetWindowText(hwndNotepad, (LPSTR) "Untitled 2"); 
  delay_ms(2000);
}

int main(void)
{
  char szPath[] = "C:\\WINDOWS\\system32\\notepad.exe";
  PROCESS_INFORMATION pif;  //Gives info on the thread and..
                           //..process for the new process
  STARTUPINFO si;          //Defines how to start the program

  ZeroMemory(&si,sizeof(si)); //Zero the STARTUPINFO struct
  si.cb = sizeof(si);         //Must set size of structure

  BOOL bRet = CreateProcess(
        szPath, //Path to executable file
        NULL,   //Command string - not needed here
        NULL,   //Process handle not inherited
        NULL,   //Thread handle not inherited
        FALSE,  //No inheritance of handles
        0,      //No special flags
        NULL,   //Same environment block as this prog
        NULL,   //Current directory - no separate path
        &si,    //Pointer to STARTUPINFO
        &pif);   //Pointer to PROCESS_INFORMATION

  if(bRet == FALSE)
  {
    MessageBox(HWND_DESKTOP,"Unable to start program","",MB_OK);
    return 1;
  } 

/* Need this delay for notepad to popup in order to get its handle*/
    delay_ms(2000);


  char szBuffer[256];
  HWND hwndNotepad;
  HWND hwndEdit;
  char cTest = 'F'; //test
  
  hwndNotepad = GetForegroundWindow(); //test
  if(!hwndNotepad)
      printf("Error getting notepad handle! \n");

//--------------- test code to get  window title --------
  int cTxtLen; 
  PSTR pszMem;   
  cTxtLen = GetWindowTextLength(hwndNotepad); 
  
  pszMem = (PSTR) VirtualAlloc((LPVOID) NULL, 
                  (DWORD) (cTxtLen + 1), MEM_COMMIT, 
                  PAGE_READWRITE); 
  GetWindowText(hwndNotepad, pszMem, 
                    cTxtLen + 1); 
  

  VirtualFree(pszMem, 0, MEM_RELEASE);
  
//--------------- set window title ----------------------------

   setNotepadTitle(hwndNotepad);

//--------------- send text to notepad -------------------------

  hwndEdit = (HWND) FindWindowEx(hwndNotepad, (HWND)NULL, (LPCTSTR)("Edit"), (LPCTSTR)NULL);
  if(!hwndEdit)
      printf("Cannot find notepad edit handle.\n");
  
  sendMsgToNotepad(hwndEdit);

//  system("pause");
  return 0;
}
