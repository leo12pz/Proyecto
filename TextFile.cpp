/* 
 * File:   TextFile.cpp
 * Author: leo
 * 
 * Created on 18 de septiembre de 2013, 02:54 PM
 */

#include "TextFile.h"

TextFile::TextFile(const string &fileName, openMode mode) {
  lineNumber = 0;
  tryOpenForInputOutPut = false;
  isOpenForInput = false;
  isOpenForOutput = false;
  
  if (mode == openForRead) {
    inputFile = new ifstream(fileName.c_str(), ios::out);
    if (inputFile)
      isOpenForInput = true;
  }
  else {
    outputFile = new ofstream(fileName.c_str(), ios::out);
    if(outputFile)
      isOpenForOutput = true;
  }
}

TextFile::TextFile(const string &inputFileName, const string &outputFileName){
  lineNumber = 0;
  tryOpenForInputOutPut = false;
  isOpenForInput = false;
  isOpenForOutput = false;
  
  inputFile = new ifstream(inputFileName.c_str(), ios::in);
  if (inputFile) {
    isOpenForInput = true;
  }
  
  outputFile = new ofstream(outputFileName.c_str(), ios::out);
  if (outputFile) {
    isOpenForOutput = true;
  }
  
  if (isOpenForInput && isOpenForOutput) {
    tryOpenForInputOutPut = true;
  }   
}

bool TextFile::write(const string & line) {
  bool status;
  (*outputFile) << line;
  
  //Revisa que el estado del flujo sea correcto
  status = outputFile->good();
  
  //Limpia las bandera de error del flujo
  outputFile->clear();
  
  return status;
}

bool TextFile::writeLine(const string &line) {
  bool status;
  (*outputFile) << line << endl;
  
  //Revisa que el estado del flujo sea correcto
  status = outputFile->good();
  
  //Limpia las bandera de error del flujo
  outputFile->clear();
  
  return status;
}

void TextFile::readLine(string &line) {
  static const int bz = 2000;
  static char buffer[bz];
  
  //Extrae caracteres de un flujo y los almacena en un buffer
  inputFile->getline(buffer, bz, '\n');
  line = string(buffer);
  lineNumber++;
}

bool TextFile::isEOF() const {
  if (isOpenForInput) {
    //Revisa si el bit de la bandera EOF esta activa   
    return inputFile->eof();
  }
  return true;
}

bool TextFile::wasOpened() {
  if (tryOpenForInputOutPut)
    return (isOpenForInput && isOpenForOutput);
  else
    return (isOpenForInput);
}

void TextFile::closeInputFile() {
  if (this->isOpenForInput) { 
      //Cierra el archivo
      inputFile->close();
      delete inputFile;
  }
}

void TextFile::closeOutputFile() {
  if (this->isOpenForOutput) {
      //Cierra el archivo
      outputFile->close();
      delete outputFile;
  }
}

void TextFile::closeFile() {
  closeInputFile();
  closeOutputFile();
}

int TextFile::getLineNumber() {
  return lineNumber;
}

void TextFile::reset() {
  if (isOpenForInput) {
    this->inputFile->seekg(0);
    this->lineNumber = 0;
  }
}

TextFile::~TextFile() {
  closeFile();
}