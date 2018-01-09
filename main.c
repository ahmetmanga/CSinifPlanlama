/*
    Programlama Lab - 2. Proje

    160202008 - Ahmet Manga
    160202033 - Zeki Esenalp

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
struct ogrenciler{
    int numara;
    char ad[100];
    char soyad[100];
    char kayitSirasi[5];
    int ogretimTuru;
    char ogretim[2];

};

void text_yaz(struct ogrenciler ogrenci[],int n,int OgretimYerlesim[],int sinifSayisi,int tur, int ogretim);

void enaz_sinif(int sinifSayisi,int Ogretim,int sinifKapasite[],int *OgretimYerlesim[]);

int esit_sinif(int sinifSayisi,int *OgretimYerlesim[],int Ogretim,int sinifKapasite[]);

int main()
{
    FILE *f,*f2;
    clock_t baslangic,bitis;
    baslangic = clock();
    struct ogrenciler ogrenci[1000];
    struct ogrenciler temp;
    int i=0,j,k,x,y,n,birinciOgretim=0,ikinciOgretim=0,esit_birinciOgretim =0,esit_ikinciOgretim = 0,artan=0;
    int kayitSiraSilinen[100],kayitSiraSayac=0,ikinciOgretimNumara=1;
    int temp_2,fark_1,fark_2,flag=0,sayac=0,esit_kalan;
    int sinifSayisi,sinifKapasite[100],birinciOgretimYerlesim[100],ikinciOgretimYerlesim[100];
    char ogrenci1_Numara[] = "1701000";
    char ogrenci2_Numara[] = "1702000";
    char strNumara[1000][1000];
    if(f = fopen("ogrenci_kayit_bilgileri.txt","r+")){
    while(!feof(f)){

        fscanf(f,"%s %s %s %s %s",&strNumara[i],&ogrenci[i].ad,&ogrenci[i].soyad,&ogrenci[i].kayitSirasi,&ogrenci[i].ogretim);
           if(strstr(ogrenci[i].ogretim,"II")) ogrenci[i].ogretimTuru = 2; else ogrenci[i].ogretimTuru = 1;

                       if(strstr(strNumara[i],"-")){
                            ogrenci[i].numara = 1;
                       }else{
                             ogrenci[i].numara = atoi(strNumara[i]);
                       }

           i++;
    }
    }
    n = i;
    printf("2 defa ismi tekrar eden ogrenci araniyor \n\n");
     for(j=1;j<n;j++){
        for(k=1;k<n;k++){
            if(strstr(ogrenci[j].ad,ogrenci[k].ad) && strstr(ogrenci[j].soyad,ogrenci[k].soyad) && j != k){
                    if(ogrenci[k].ad[0] != NULL){
                         printf("%s %s - %s.Ogretim - %s Silindi \n",ogrenci[k].ad,ogrenci[k].soyad,ogrenci[k].ogretim,ogrenci[k].kayitSirasi);
                         kayitSiraSilinen[kayitSiraSayac] = atoi(ogrenci[k].kayitSirasi);
                         kayitSiraSayac++;
                    }

                    for(x=1;x<n;x++){
                    if(x>=k){
                        if((x+1) <= i){
                            ogrenci[x] = ogrenci[x+1];
                        }else{
                            ogrenci[x].numara = 0;
                        }

                    }
                }
            }
        }
      }

      // silinen kayit siralari kucukten buyuge siralaniyor.
        for(i=1;i<kayitSiraSayac;i++){
            for(j=0;j<kayitSiraSayac-1;j++){
                if(kayitSiraSilinen[j] > kayitSiraSilinen[j+1]){
                    temp_2 = kayitSiraSilinen[j];
                    kayitSiraSilinen[j] = kayitSiraSilinen[j+1];
                    kayitSiraSilinen[j+1] = temp_2;
                }
            }
        }

        for(j=0;j<kayitSiraSayac;j++){
            for(i=1;i<n;i++){
                if(atoi(ogrenci[i].kayitSirasi) + ((j*(j+1))/2) > kayitSiraSilinen[j]){
                    itoa(atoi(ogrenci[i].kayitSirasi)-(1*(j+1)),ogrenci[i].kayitSirasi,10);
                }
            }
        }
      printf("\n2 'den fazla tekrar eden ogrenci yoktur.\n\n");
      printf("Kayit Sira Bilgileri Guncellendi.\n\n");
    // dizi boyutu bul
     for(k=1;k<i;k++){
        if(ogrenci[k].numara == 0) break;
     }
     n = k;
            // kayit siraya gore sirala.
         for(i=1;i<n;i++){
        for(j=1;j<n-1;j++){
            if(atoi(ogrenci[j].kayitSirasi) > atoi(ogrenci[j+1].kayitSirasi)){
                temp = ogrenci[j];
                ogrenci[j] = ogrenci[j+1];
                ogrenci[j+1] = temp;
            }
        }
    }


            for(k=1;k<n;k++){
            if(ogrenci[k].ogretimTuru == 2) ikinciOgretim++; else birinciOgretim++;
        if(ogrenci[k].numara == 1){

                if(ogrenci[k].ogretimTuru == 1){
                        ogrenci[k].numara = atoi(ogrenci1_Numara);
                        ogrenci[k].numara += atoi(ogrenci[k].kayitSirasi);

                }else{
                        ogrenci[k].numara = atoi(ogrenci2_Numara);
                        ogrenci[k].numara += ikinciOgretimNumara;
                        ikinciOgretimNumara++;

                }
        }
    }
/* numara icin kontrol */
 for(k=1;k<n;k++){
        int kontrol = 0;
                 while(kontrol == 0){
                    for(j=1;j<n;j++){
                    if(j != k && atoi(ogrenci[k].kayitSirasi) == atoi(ogrenci[j].kayitSirasi) && atoi(ogrenci[j].kayitSirasi) != 0){
                        itoa(atoi(ogrenci[j].kayitSirasi)+1,ogrenci[j].kayitSirasi,10);
                        if(ogrenci[j].ogretimTuru == 1){
                            ogrenci[j].numara = atoi(ogrenci1_Numara);
                            ogrenci[j].numara += atoi(ogrenci[j].kayitSirasi);
                        }
                            kontrol = 0;
                            break;
                    }else{
                    kontrol = 1;
                    }

                }

                 }
    }
    printf("Yeni kayit olan ogrencilere numara verildi.\n");
          tekrar_Sirala:  for(i=1;i<n;i++){
        for(j=1;j<n-1;j++){
            if(ogrenci[j].numara > ogrenci[j+1].numara){
                temp = ogrenci[j];
                ogrenci[j] = ogrenci[j+1];
                ogrenci[j+1] = temp;
            }
        }
    }
        printf("\nOgrenciler numaraya gore siralandi.\n");
        int secim;
        printf("\nYeni kullanici girmek istermisiniz? (0: Evet) ");
        scanf("%d",&secim);
        if(secim == 0){
            printf("Kac adet ogrenci girmek istediginizi yazin : ");
            scanf("%d",&i);
            for(j=0;j<i;j++){
                printf("[%d] - Numara Girin: ",j+1);
                scanf("%d",&ogrenci[j+n].numara);
                printf("[%d] - Ad Girin: ",j+1);
                scanf("%s",&ogrenci[j+n].ad);
                 printf("[%d] - Soyad Girin: ",j+1);
                scanf("%s",&ogrenci[j+n].soyad);
                 printf("[%d] - Kayit Sirasi Girin: ",j+1);
                scanf("%s",&ogrenci[j+n].kayitSirasi);
                 printf("[%d] - Ogretim Turu: ",j+1);
                scanf("%s",&ogrenci[j+n].ogretim);
                 if(strstr(ogrenci[j+n].ogretim,"II")) {
                    ikinciOgretim++;
                    ogrenci[j+n].ogretimTuru = 2;
                    }else{
                    birinciOgretim++;
                    ogrenci[j+n].ogretimTuru = 1;
                    }

            }
            n += i;
            goto tekrar_Sirala;

        }
        f2 = fopen("guncel_ogrenci_kayit_bilgileri.txt","w+");
         fprintf(f2,"%-10s %-10s %-10s %-20s %-15s\n","OgrNo","Ad","Soyad","KayitSirasi","OgretimTuru");
        for(k=1;k<n;k++)    fprintf(f2,"%-10d %-10s %-10s %-20s %-15s\n",ogrenci[k].numara,ogrenci[k].ad,ogrenci[k].soyad,ogrenci[k].kayitSirasi,ogrenci[k].ogretim);

        bitis = clock();
        printf("\n\nSuana kadar programin calisma suresi %d saniye\n\n",(bitis-baslangic)/1000);
        printf("Dersi alan ogrenci sayisi \n1. Ogretim : %d\n2. Ogretim : %d\n\n",birinciOgretim,ikinciOgretim);
        printf("Sinif Sayisini Giriniz: ");
        scanf("%d",&sinifSayisi);
        int kapasiteTopla;
        kapasite_Tekrarla:
        kapasiteTopla = 0;
        printf("Sinif kapasitelerini giriniz: \n");
        for(i=0;i<sinifSayisi;i++)
        {
            scanf("%d",&sinifKapasite[i]);
            kapasiteTopla += sinifKapasite[i];
        }
        if(kapasiteTopla < birinciOgretim || kapasiteTopla < ikinciOgretim) goto kapasite_Tekrarla;


        //kapasite bubble sort

        for(i=1;i<sinifSayisi;i++){
        for(j=0;j<sinifSayisi-1;j++){
            if(sinifKapasite[j] > sinifKapasite[j+1]){
                temp_2 = sinifKapasite[j];
                sinifKapasite[j] = sinifKapasite[j+1];
                sinifKapasite[j+1] = temp_2;
            }
        }
    }
    // tum siniflari sifir yaptik

        for(i=0;i<sinifSayisi*2;i++){

            birinciOgretimYerlesim[i] = 0;
            ikinciOgretimYerlesim[i] = 0;

        }
        esit_birinciOgretim = birinciOgretim;
        esit_ikinciOgretim = ikinciOgretim;

            enaz_sinif(sinifSayisi,birinciOgretim,sinifKapasite,&birinciOgretimYerlesim); // 1. ö?retim

            enaz_sinif(sinifSayisi,ikinciOgretim,sinifKapasite,&ikinciOgretimYerlesim); // 2. ö?retim

            text_yaz(ogrenci,n,birinciOgretimYerlesim,sinifSayisi,0,1); // 1. ö?retim yazdir

            text_yaz(ogrenci,n,ikinciOgretimYerlesim,sinifSayisi,0,2); // 2. ö?retim yazdir

    printf("\nEn az sinif dagilimi\n\n");
    printf("I. Ogretim Duzeni : \n");
    for(i=sinifSayisi-1;i>=0;i--){
        printf("Sinif[%d] Kapasite : %d - Ogrenci Sayisi : %d \n",i+1,sinifKapasite[i],birinciOgretimYerlesim[i]);
    }
    printf("II. Ogretim Duzeni : \n");
    for(i=sinifSayisi-1;i>=0;i--){
        printf("Sinif[%d] Kapasite : %d - Ogrenci Sayisi : %d \n",i+1,sinifKapasite[i],ikinciOgretimYerlesim[i]);
    }

 // esit dagilim basliyor.


     // tum siniflari sifir yaptik
     for(i=0;i<sinifSayisi*2;i++){

            birinciOgretimYerlesim[i] = 0;
            ikinciOgretimYerlesim[i] = 0;

        }

           esit_sinif(sinifSayisi,&birinciOgretimYerlesim,esit_ikinciOgretim,sinifKapasite); // 1. ö?retim

           esit_sinif(sinifSayisi,&ikinciOgretimYerlesim,esit_ikinciOgretim,sinifKapasite); // 2. ö?retim

           text_yaz(ogrenci,n,birinciOgretimYerlesim,sinifSayisi,1,1); // 1. ö?retim yazdir

           text_yaz(ogrenci,n,ikinciOgretimYerlesim,sinifSayisi,1,2); // 2. ö?retim yazdir

    printf("\n\nEsit Dagilim\n\n");
    printf("I. Ogretim Duzeni \n");
    for(i=0;i<sinifSayisi;i++){
        printf("Sinif[%d] Kapasite : %d - Ogrenci Sayisi : %d\n",i+1,sinifKapasite[i],birinciOgretimYerlesim[i]);
    }
    printf("II. Ogretim Duzeni \n");
    for(i=0;i<sinifSayisi;i++){
        printf("Sinif[%d] Kapasite : %d - Ogrenci Sayisi : %d\n",i+1,sinifKapasite[i],ikinciOgretimYerlesim[i]);
    }

    bitis = clock();
    printf("\n\nProgramin Tum Calisma Suresi %d saniye\n\n",(bitis-baslangic)/1000);
    return 0;
}


void text_yaz(struct ogrenciler ogrenci[],int n,int OgretimYerlesim[],int sinifSayisi,int tur, int ogretim){

 FILE *f2;
 int i,j,k=1,sayac;

 char tur_1[] = "_EnAz.txt";
 char tur_2[] = "_Esit.txt";
     k = 1;
            for(i=0;i<sinifSayisi;i++){
            if(OgretimYerlesim[i] != 0){
                    char dosya_ismi[] = "Sinif";
                    char dosya_sira[5];
                        itoa(i+1,dosya_sira,10);
                        strcat(dosya_ismi,dosya_sira);
                        if(ogretim == 1) strcat(dosya_ismi,"Ogr1"); else strcat(dosya_ismi,"Ogr2");
                        if(tur == 0) strcat(dosya_ismi,"_EnAz.txt"); else strcat(dosya_ismi,"_Esit.txt");
                        f2 = fopen(dosya_ismi,"w+");
                       fprintf(f2,"%-10s %-10s %-10s %-20s %-15s\n","OgrNo","Ad","Soyad","KayitSirasi","OgretimTuru");
                            sayac = 0;

                            for(j=k;j<n;j++){
                                if(sayac <= OgretimYerlesim[i] && ogrenci[j].ogretimTuru == ogretim){
                                     fprintf(f2,"%-10d %-10s %-10s %-20s %-15s\n",ogrenci[j].numara,ogrenci[j].ad,ogrenci[j].soyad,ogrenci[j].kayitSirasi,ogrenci[j].ogretim);
                                    sayac++;
                                }
                                k++;
                                if(sayac >= OgretimYerlesim[i]) break;

                            }
            }
    }

}

void enaz_sinif(int sinifSayisi,int Ogretim,int sinifKapasite[],int *OgretimYerlesim[]){

    int i,j;
    int fark_1,flag = 0,fark_2;
        for(i=sinifSayisi-1;i>=0;i--){
              if(Ogretim > sinifKapasite[i]){

                    OgretimYerlesim[i] = sinifKapasite[i];
                    Ogretim -= sinifKapasite[i];

              }else{
                    fark_1 = sinifKapasite[i] - Ogretim;

                        if(fark_1 == 0){

                                OgretimYerlesim[i] = Ogretim;
                                Ogretim -= sinifKapasite[i];
                        }else{

                                for(j=i-1;j>=0;j--){
                            fark_2 = sinifKapasite[j] - Ogretim;

                            if(fark_2 < fark_1 &&  OgretimYerlesim[j] == 0 && fark_2 >= 0){

                                OgretimYerlesim[j] = Ogretim;
                                Ogretim = 0;
                                flag = 1;
                            }
                        }
                        if(flag == 0 && fark_1 > 0){
                            OgretimYerlesim[i] = Ogretim;
                            Ogretim = 0;
                        }
                    }
              }
                if(Ogretim == 0) break;
        }
}

int esit_sinif(int sinifSayisi,int *OgretimYerlesim[],int Ogretim,int sinifKapasite[]){
int k,i,flag = 0,artan,esit_kalan;
k = floor(Ogretim/sinifSayisi);
    flag = 0;
        for(i=0;i<sinifSayisi;i++){
                if(k > sinifKapasite[i]){
                        flag = 1;
                        break;
                }
        }

        if(flag == 0){
        for(i=0;i<sinifSayisi;i++) OgretimYerlesim[i] = k;

        artan = Ogretim - sinifSayisi*k;
         if(artan > 0) goto dagit; else return 1;
        dagit : for(i=0;i<sinifSayisi;i++){
            if((1+OgretimYerlesim[i]) <= sinifKapasite[i]){
                OgretimYerlesim[i] += 1;
                artan--;
            }

           if(artan <= 0) break;
        }
            if(artan > 0) goto dagit;

    }else{
       // int toplam = 0;
        artan = 0;
        esit_kalan = sinifSayisi;
        for(i=0;i<sinifSayisi;i++){
                k = floor(Ogretim/esit_kalan);
            if(sinifKapasite[i] < k){
                OgretimYerlesim[i] = sinifKapasite[i];
                Ogretim -= sinifKapasite[i];

                esit_kalan--;
            }else{

                k = floor((Ogretim)/esit_kalan);
                OgretimYerlesim[i] = k;

            }

        }

    }
    return 1;
}

