using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hafta5_nyp_2
{
    internal class Program
    {
        static Boolean ParcaUygunMu (int puan,int sira)
        {
            if (puan >= 80)
            {
                return true;
                Console.WriteLine(sira + ". parca uygundur");
            }
            else
            {
                return false;
                Console.WriteLine(sira + ". parca uygun değildir");
            }
        }
        static void Main(string[] args)
        {
            int[] parcaKaliteleri = new int[8];
            for(int i=0; i<8; i++)
            {
                Console.WriteLine((i+1) + ".parça kalitesini giriniz (0-100)=");
                parcaKaliteleri[i] = Convert.ToInt32(Console.ReadLine());
                ParcaUygunMu(parcaKaliteleri[i], (i + 1));
            }
        }
    }
}
