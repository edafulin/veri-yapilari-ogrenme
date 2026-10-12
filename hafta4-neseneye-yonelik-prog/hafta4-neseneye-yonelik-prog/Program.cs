using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hafta4_neseneye_yonelik_prog
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int toplamkar = 0;
            double[] sureler = new double [10];
            double enUzun = 0;
            int bes_saatten_fazla = 0;
            int enUzunKalanArac = 0;
            double toplam = 0.0;
            for (int i = 0; i < 10; i++)
            {
                Console.Write("{0}. araç kaç saat kaldı?\t",i+1);
                sureler[i] = Convert.ToDouble(Console.ReadLine());
                toplam += sureler[i];
            }
            int[] ucretler = new int [10];
            for (int i = 0; i < 10; i++)
            {
                if (sureler[i] > 5.0)
                {
                    bes_saatten_fazla += 1;
                }
                if (1.0 < sureler[i] && sureler[i] < 2.0)
                {
                    ucretler[i] = 50;
                }
                else if (3.0 < sureler[i] && sureler[i] < 5.0)
                {
                    ucretler[i] = 100;
                }
                else if (6 < sureler[i])
                {
                    ucretler[i] = 200;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                toplamkar += ucretler[i];
                if (sureler[i] > enUzun)
                {
                    enUzun = sureler[i];
                    enUzunKalanArac = i + 1;
                }
            }
            Console.WriteLine("toplam geliriniz =  {0}", toplamkar);
            Console.WriteLine("en uzun sure kalan arac ve suresi = {0}\t{1}", enUzunKalanArac,enUzun);
            Console.WriteLine("5 saatten uzun kalan arac sayisi = {0}",bes_saatten_fazla);
            double ortalama =Convert.ToDouble(toplam) / 10.0;
            Console.WriteLine("ortalamaniz= {0}",ortalama);
        }
    }
}
