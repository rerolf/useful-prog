#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc,char* argv[])
{
  std::string path = "Dictionary.txt";
  std::fstream fout;
  fout.open(path,std::fstream::in | std::fstream::out | std::fstream::app);
  if(!fout.is_open()){
    std::cout << "Error opening the file.\n";
  }
  if((argc<2)&&(argc>3)){
    std::cout << "Type ./dictionary help for info\n";
    return 1;
  }
  else if(argc==2){
    std::string help = "help";
    std::string read = "read";
    std::string write = "write";
    if(argv[1]==write){
    std::string msg1,msg2;
    std::cout << "Enter the original word: ";
    getline(std::cin,msg1);
    std::cout << "Enter translation: ";
    getline(std::cin,msg2);
    msg1 ="\x1b[33m"+msg1+"\x1b[37m" + "\t" + "---" + "\t" + msg2+ "\n";
    fout << msg1;
    }
    if(argv[1]==read){
      std::string msg="";
      std::vector<std::string> arr;
      while(!fout.eof()){
        while(getline(fout,msg)){
          arr.push_back(msg);
        }
        std::sort(arr.begin(),arr.end());
        for(std::vector<string>::iterator i = arr.begin(); i != arr.end(); i++)
        {
          cout << *i << "\n";
        }
      }
    }
    if(argv[1]==help){
      std::cout << "Using:\n./dictionary find\ttofind the word in dictionary\n";
      std::cout << "./dictionary read\tto read the whole dictionary\n";
      std::cout << "./dictionary write\tto add word and translation in dictionary\n";
    }
    if((argv[1]!=help)&&(argv[1]!=read)&&(argv[1]!=write))std::cout << "Type ./dictionary help for info\n";
  }
  else if(argc==3){
    std::string find = "find";
    if(argv[1]==find){
      std::string msg;
      std::string name = argv[2];
      while(!fout.eof()){
        while(getline(fout,msg)){
          if(msg.find(name) != -1)std::cout << msg<<"\n";
        }
      }
    }
    else if(argv[1]!=find) std::cout << "Type ./dictionary help for info\n";
  }
  fout.close();
  return 0;
}
