using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hafta_5_nesneye_yonelik_prog
{
    internal class Program
    {
        static double ortalamaHesapla(int vize, int final)
        {
            double ortalama = final*0.6 + vize*0.4;
            return ortalama;
        }
        static Boolean basariliMi(double ortalama)
        {
            if (ortalama > 60.0)
                return true;
            else {
                return false;
            }
        }
        
        
        static void Main(string[] args)
        {
            int[] vizeler = new int[5];
            int[] finaller = new int[5];
            double[] ortalamalar = new double[5];
            int basariliOgrenciSayisi = 0;
            for (int i = 0; i < 5; i++) {
                Console.Write((i+1) + ". öğrencinin vize notunu giriniz:");
                vizeler[i] = Convert.ToInt32(Console.ReadLine());
                Console.Write((i + 1)  + ". öğrencinin final notunu giriniz:");
                finaller[i] = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();
            }
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine((i+1) + ". ogrenci ortalamasi =" + ortalamaHesapla(vizeler[i], finaller[i]));
                ortalamalar[i] = ortalamaHesapla(vizeler[i], finaller[i]);
            }

            for (int i = 0; i < 5; i++) 
            { 
               if(basariliMi(ortalamalar[i]) == true)
                    basariliOgrenciSayisi++;
            }
            Console.WriteLine("basarili öğrenci sayisi = " + basariliOgrenciSayisi);

           
        }
    }
}
