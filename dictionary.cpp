#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
int main(int argc,char* argv[])
{
  std::string path = "Dictionary.txt";
  std::fstream fout;
  fout.open(path,std::fstream::in | std::fstream::out | std::fstream::app);
  if(!fout.is_open()){
    std::cout << "Ошибка открытия файла.\n";
  }
  else{
    std::string help = "help";
    std::string find = "find";
    std::string read = "read";
    std::string write = "write";
    if(argv[1]==write){
    std::string msg1,msg2;
    std::cout << "Enter the original word: ";
    msg1="test";
    std::cin >> msg1;
    std::cout << "Enter translation: ";
    msg2="testt";
    std::cin >> msg2;
    msg1 ="\x1b[31m"+msg1+"\x1b[37m" + "\t" + "---" + "\t" + msg2 +"\n";
    fout << msg1;
    }
    if(argv[1]==read){
      std::string msg;
      while(!fout.eof()){
        msg="";
        while(getline(fout,msg)){
          std::cout << msg<<"\n";
        }
      }
    }
    if(argv[1]==find){
//coming soon
    }
    if(argv[1]==help){
      std::cout << "Using:\n./dictionary find\ttofind the word in dictionary\n";
      std::cout << "./dictionary read\tto read the whole dictionary\n";
      std::cout << "./dictionary write\tto add word and translation in dictionary\n";
    }
    if((argv[1]!=help)&&(argv[1]!=find)&&(argv[1]!=read)&&(argv[1]!=write))std::cout << "Type ./dictionary help for info\n";
  }
  fout.close();
  return 0;
}
