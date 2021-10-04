# CPP labs

## Lab #1
Реализовать консольную утилиту, считающую хеш от файла.  

Утилита может считать 2 варианта хеша:  
 - Adler32 [wiki](https://en.wikipedia.org/wiki/Adler-32);  
 - 64-битный хеш через сумму 64-битных блоков данных.  

Утилита принимает имя файла и вариант расчета хеша как аргументы командной строки.  

[Ссылка на условие](https://docs.google.com/document/d/1XQaskdDSamHJdVFXKDGbnMsQXN8Xq4ykVtY2fi1tTwg/edit)

#### Compile
```shell
$ mkdir build; cd build;
$ cmake ..; make -j8; cd ..
```

#### Run
```shell
$ build/lab1/cpp_labs_1 --help                                                                                                     ✔  12:09:21 
error: the option '--filename' is required but missing
help: Варианты запуска программы:
  -h [ --help ]                вывести справочную
                               информацию об
                               использовании и завершить
                               работу;
  -f [ --filename ] arg        посчитать переданный
                               вариант хеша переданного
                               файла;
  -m [ --mode ] arg (=adler32) adler32 или sum64
```
