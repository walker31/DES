#ifndef DES_H
#define DES_H

#include <QString>
#include <string>

QString HexArrayToString(int * a);                      //字节数组转换成字符串
QString EncodeMain(QString mingwen,QString q_key);      //完整加密函数
QString DecodeMain(QString miwen,QString q_key2);       //完整解密函数

void Decode(int *str,int *keychar);   //加密函数
void Encode(int *str,int *keychar);   //解密函数

void keyBuild(int *keychar);          //创建K
void StrtoBin(int *midkey,int *keychar);  //字符串转换成2进制流
void keyCreate(int *midkey2,int movebit,int i);  //创建K的操作, 有KeyBuild调用

void EncodeData(int *lData,int *rData,int *srt); //加密明文函数
void F(int *rData,int *key);                     //F函数

void Expand(int *rData,int *rDataP);             //48位拓展成64位
void ExchangeS(int *rDataP,int *rData);          //S变换
void ExchangeP(int *rData);                   //P 变换

void FillBin(int *rData,int n,int s);              // 转换成2进制, 由S变换调用
void DecodeData(int *str,int *lData,int *rData);   //解密密文



int IP1[]={58, 50, 42, 34, 26, 18, 10, 2,  60, 52, 44, 36, 28, 20, 12, 4,    //IP变换
           62, 54, 46, 38, 30, 22, 14, 6,  64, 56, 48, 40, 32, 24, 16, 8,
           57, 49, 41, 33, 25, 17, 9,  1,  59, 51, 43, 35, 27, 19, 11, 3,
           61, 53, 45, 37, 29, 21, 13, 5,  63, 55, 47, 39, 31, 23, 15, 7,
 };
int IP2[]={40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,    //IP逆变换
           38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
           36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
           34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
 };
int s[][4][16]={{                                                   //S盒子
                 {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                 {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                 {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                 {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
                 },
                {
                 {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                 {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                 {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                 {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
                },
                {
                 {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                 {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                 {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                 {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
                },
                {
                 {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                 {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                 {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                 {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
                },
                {
                 {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                 {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                 {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                 {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
                },
                {
                 {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                 {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                 {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                 {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
                },
                {
                 {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                 {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                 {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                 {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
                },
                {
                 {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                 {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                 {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                 {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
                }
};
int Ex[48]={  32,1,2,3,4,5,                                       //32->48位拓展
              4,5,6,7,8,9,
              8,9,10,11,12,13,
              12,13,14,15,16,17,
              16,17,18,19,20,21,
              20,21,22,23,24,25,
              24,25,26,27,28,29,
              28,29,30,31,32,1
 };
int P[32]={16,7,20,21,                                            //P表
           29,12,28,17,
           1,15,23,26,
           5,18,31,10,
           2,8,24,14,
           32,27,3,9,
           19,13,30,6,
           22,11,4,25
 };
int PC1[56]={57,49,41,33,25,17,9,                               //PC1表
             1,58,50,42,34,26,18,
             10,2,59,51,43,35,27,
             19,11,3,60,52,44,36,
             63,55,47,39,31,33,15,
             7,62,54,46,38,30,22,
             14,6,61,53,45,37,29,
             21,13,5,28,20,12,4
 };
int PC2[48]={14,17,11,24,1,5,                                  //PC2表
             3,28,15,6,21,10,
             23,19,12,4,26,8,
             16,7,27,20,13,2,
             41,52,31,37,47,55,
             30,40,51,45,33,48,
             44,49,39,56,34,53,
             46,42,50,36,29,32
};


static int key[16][48];
static char str[8];
static int strkey[8];
static int strkey_bak[8];
static char keychar[8];
static int key2[8];


QString EncodeMain(QString mingwen,QString q_key)      //包括准备工作的完整加密过程
{
  int i;
  char *temp_c;
  QString result;

  QByteArray t_str1 = mingwen.toLatin1();        //明文转化成Latin字符集
  temp_c = t_str1.data();       //获取明文的内容


  for ( i = 0; i < 8; i++) {        //读取明文内容
      str[i] = *(temp_c + i );
      strkey[i] = str[i];
     ;
  }

  t_str1 = q_key.toLatin1();   //密钥K转换成Latin字符集
  temp_c = t_str1.data();      //获取密钥K的内容
  for ( i = 0; i < 8; i++ ) {       //读取密钥K的内容
      keychar[i] = *( temp_c + i );
      key2[i] = keychar[i];
  }

  Encode(strkey,key2);       //用key2在strkey上直接加密

  for (i =0;i<8;i++){
      strkey_bak[i] = strkey[i];
  }
  result = HexArrayToString(strkey);    //将十六进制转换成字符串
  return result;
}

//完整的解密函数
QString DecodeMain(QString miwen,QString q_key2)
{
  int i;
  char *temp_c;
  QString result;
  QByteArray t_str2 = q_key2.toLatin1();
  temp_c = t_str2.data();

  for(i=0;i<8;i++) {        //获取密钥内容
     keychar[i] = *(temp_c + i);
     key2[i]=keychar[i];
 }

  for(i=0;i<8;i++)          //获得密文的内容
  {
      strkey[i]=strkey_bak[i];
  }

  Decode(strkey,key2); //解密之

  for(i=0;i<8;i++)
    str[i] = (char) strkey[i];


  for ( i = 0; i < 8; i++ ) {
      result.append(str[i]);
  }

  return result;
}


void keyBuild(int *keychar){             //根据规则移位由K得到各种Ki
    int i;
    int movebit[]={1,1,2,2,2,2,2,2,    //移位表
                   1,2,2,2,2,2,2,1};

    int midkey[64];
    int midkey2[56];

    StrtoBin(midkey,keychar);

    for(i=0;i<56;i++) {
        int t = PC1[i];
        midkey2[i]=midkey[t-1];
  }
    for(i=0;i<16;i++)
      keyCreate(midkey2,movebit[i],i);
   }

//将给定的字符串改写成二进制
void StrtoBin(int *midkey,int *keychar){
    int trans[8],i,j,k,n;
    n=0;
    for(i=0;i<8;i++){
        j=0;
        while(keychar[i]!=0){
            trans[j]=keychar[i]%2;               //除二取余
            keychar[i]=keychar[i]/2;
            j++;
        }
        for(k=j;k<8;k++)trans[k]=0;       //后面补0
        for(k=0;k<8;k++)
           midkey[n++]=trans[7-k];         //逆转, 生成对应的二进制
    }
   }
//根据Movebit[]循环左移
void keyCreate(int *midkey2,int movebit,int n){
    int i,temp[4];
    temp[0]=midkey2[0];
    temp[1]=midkey2[1];
    temp[2]=midkey2[28];
    temp[3]=midkey2[29];
   if(movebit==2){
       for(i=0;i<26;i++){
         midkey2[i]=midkey2[i+2];
         midkey2[i+28]=midkey2[i+30];
       }
       midkey2[26]=temp[0];midkey2[27]=temp[1];
       midkey2[54]=temp[2];midkey2[55]=temp[3];  }
     else
     { for(i=0;i<27;i++){
        midkey2[i]=midkey2[i+1];
        midkey2[i+28]=midkey2[i+29];
       }
       midkey2[27]=temp[0];midkey2[55]=temp[2];
     }

   //PC2变换
    for(i=0;i<48;i++) {
        int t = PC2[i];
        key[n][i]=midkey2[t-1];
  }
}

//具体的加密函数
void EncodeData(int *lData,int *rData,int *str){
    int i,j,temp[8],lint,rint;
    int data[64];
    lint=0,rint=0;
    for(i=0;i<4;i++){
       j=0;
       while(str[i]!=0){
         temp[j]=str[i]%2;
         str[i]=str[i]/2;
         j++;
       }
       while(j<8)temp[j++]=0;
       for(j=0;j<8;j++)
        lData[lint++]=temp[7-j];
       j=0;
       while(str[i+4]!=0){
        temp[j]=str[i+4]%2;
        str[i+4]=str[i+4]/2;
        j++;
       }
       while(j<8)temp[j++]=0;
       for(j=0;j<8;j++)rData[rint++]=temp[7-j];
    }
    for(i=0;i<32;i++){
       data[i]=lData[i];
       data[i+32]=rData[i];
    }

    for(i=0;i<32;i++){
        int t = IP1[i];
        lData[i]=data[t-1];
        t = IP1[i+32];
        rData[i]=data[t-1];
    }
}

//f变换
void F(int *rData,int *key){
    int i,rDataP[48];
    Expand(rData,rDataP);

    for(i=0;i<48;i++){
      rDataP[i]=rDataP[i]^key[i];
      }

    ExchangeS(rDataP,rData);
    ExchangeP(rData);


   }

//位拓展函数
void Expand(int *rData,int *rDataP){
    int i;
    for(i=0;i<48;i++) {
        int t = Ex[i];
        rDataP[i]=rData[t-1];
      //rDataP[i]=rData[Ex[i]-1];
  }
}

//S盒子变换
void ExchangeS(int *rDataP,int *rData){
    int i,n,linex,liney;
    linex=liney=0;
    for(i=0;i<48;i+=6){
        n=i/6; //printf("%10d\n",(rDataP[i]<<1));
        linex=(rDataP[i]<<1)+rDataP[i+5];
        liney=(rDataP[i+1]<<3)+(rDataP[i+2]<<2)+(rDataP[i+3]<<1)+rDataP[i+4];

        FillBin(rData,n,s[n][linex][liney]);
    }
}

//P变换
void ExchangeP(int *rData){
    int i,temp[32];
    for(i=0;i<32;i++)
      temp[i]=rData[i];

    for(i=0;i<32;i++) {
        int t = P[i];
        rData[i]=temp[t-1];
      //rData[i]=temp[P[i]-1];
  }
}

//数据改写成二进制, 由S盒子变换调用
void FillBin(int *rData,int n,int s){
    int temp[4],i;
    for(i=0;i<4;i++){
        temp[i]=s%2;
        s=s/2;
        }
    for(i=0;i<4;i++)
        rData[n*4+i]=temp[3-i];
}

//从二进制解密
void DecodeData(int *str,int *lData,int *rData){
    int i;int a,b;int data[64];
    a=0,b=0;
    for(i=0;i<32;i++){
        data[i]=lData[i];
        data[i+32]=rData[i];
    }
    for(i=0;i<32;i++){
        int t = IP2[i];
        lData[i]=data[t-1];
        t = IP2[i+32];
        rData[i]=data[t-1];
    }
    for(i=0;i<32;i++){
        a=(lData[i]&0x1)+(a<<1);
        b=(rData[i]&0x1)+(b<<1);
        if((i+1)%8==0){
            str[i/8]=a;a=0;
            //printf("%d",i/8);
            str[i/8+4]=b;b=0;
            //printf("%d",i/8+4);
        }
    }
}


/*上层的加密调用函数, 调用
KeyBuild(), EncodeData()和DecodeData()
*/
void Encode(int *str,int *keychar){
   int lData[32],rData[32],temp[32];
   int i,j;
   keyBuild(keychar);   //创建密钥K

   EncodeData(lData,rData,str); //加密

   for(i=0;i<16;i++){
     for(j=0;j<32;j++)
        temp[j]=rData[j];

     F(rData,key[i]);   //变换

     for(j=0;j<32;j++){ //Li部分与上f(Ri, Ki)
        rData[j]=rData[j]^lData[j];
     }

     for(j=0;j<32;j++)  //Li与Ri互换
        lData[j]=temp[j];
   }

   DecodeData(str,rData,lData);

}

/*上层的解密调用函数, 调用
KeyBuild(), EncodeData()和DecodeData()
*/
void Decode(int *str,int *keychar){
   int lData[32],rData[32],temp[32];
   int i,j;
   keyBuild(keychar);   //创建密钥K
   EncodeData(lData,rData,str);     //解密
   for(i=0;i<16;i++){                       //同上, 逆回去
     for(j=0;j<32;j++)
        temp[j]=rData[j];
     F(rData,key[15-i]);
     for(j=0;j<32;j++){
        rData[j]=rData[j]^lData[j];
     }

     for(j=0;j<32;j++){
        lData[j]=temp[j];
        }
   }
   DecodeData(str,rData,lData);
}

//16进制转换成字符串
QString HexArrayToString(int * a)
{
    QString result;
    char c[5];
    int j;
    for( j = 0; j < 8; j++) {
        int x = a[j];
        int i = 0,n;
        while ( x > 0 ) {
            n = x % 16;
            if ( n < 10 )
                c[i] = n + '0';
            else
                c[i] = n - 10 + 'A';
            x = x / 16;
            i++;
        }
        c[i] = '\0';
        n = i - 1;
        i = 0;
        while ( i < n ) {
            char t = c[i];
            c[i] = c[n];
            c[n] = t;
            i++;
            n--;
        }

        for ( i = 0; i < 2; i++ ) {
            result.append(c[i]);
        }
        result.append(' ');
    }

    return result;
}

#endif
