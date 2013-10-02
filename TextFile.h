/* 
 * File:   TextFile.h
 * Author: leo
 *
 * Created on 18 de septiembre de 2013, 02:54 PM
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include <iostream>
using std::ios;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

enum openMode{openForRead, openForWrite};

class TextFile {
public:
  TextFile(const string &, openMode);
  TextFile(const string &, const string &);
  bool writeLine(const string &);
  bool write(const string &);
  void readLine(string &);
  bool isEOF() const;
  bool wasOpened();
  void closeFile();
  int getLineNumber();
  void reset();
  ~TextFile();
private:
  int lineNumber;
  void closeInputFile();
  void closeOutputFile();
  bool tryOpenForInputOutPut;
  bool isOpenForInput;
  bool isOpenForOutput;
  //Permiten operaciones de lectura y escritura en archivos 
  ifstream * inputFile;   
  ofstream * outputFile;  
};
#endif	

