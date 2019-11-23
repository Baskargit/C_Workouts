using System;

namespace TopCoder
{
    class LotteryTicket
    {
        static void Main(string[] args)
        {
            int price,b1,b2,b3,b4;

            price = Convert.ToInt32(Console.ReadLine());

            b1 = Convert.ToInt32(Console.ReadLine());
            b2 = Convert.ToInt32(Console.ReadLine());
            b3 = Convert.ToInt32(Console.ReadLine());
            b4 = Convert.ToInt32(Console.ReadLine());

            // price = 10;
            // b1 = 1;
            // b2 = 5;
            // b3 = 10;
            // b4 = 50;

            LotteryTicket obj = new LotteryTicket();

            Console.WriteLine(obj.buy(price,b1,b2,b3,b4));
        }

        public string buy(int price, int b1, int b2, int b3, int b4)
        {
            if(b1 == price || b2 == price || b3 == price || b4 == price) {
                return "POSSIBLE";
            } else if(b1 + b2 + b3 + b4 == price) {
                return "POSSIBLE";
            } else if((b1+b2) == price || (b1+b3) == price || (b1+b4) == price ||
                        (b2+b3) == price || (b2+b4) == price
                            || (b3+b4) == price) {
                return "POSSIBLE";
            } else if((b1+b2+b3) == price || (b1+b2+b4) == price || (b2+b3+b4) == price) {
                return "POSSIBLE";
            }

            return "IMPOSSIBLE";
        }

    }
}
