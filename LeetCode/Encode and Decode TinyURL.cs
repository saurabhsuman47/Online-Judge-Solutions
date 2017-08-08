public class Codec
    {
        private long mod;
        private long span;
        Hashtable htShortToLong;
        Hashtable htLongToShort;

        public Codec()
        {
            span = 62;
            mod = (long)Math.Pow(62, 6);
            htShortToLong = new Hashtable();
            htLongToShort = new Hashtable();
        }

        // Encodes a URL to a shortened URL
        public string encode(string longUrl)
        {
            string result;
            if (htLongToShort.ContainsKey(longUrl))
            {
                result = @"http://tinyurl.com/" + (string)htLongToShort[longUrl];
                return result;
            }
            long val = 1;
            for (int i = 0; i < longUrl.Length; i++)
            {
                long asciiVal = longUrl[i];
                val = (val * asciiVal) % mod;
            }
            
            string encodedStr = "";
            for (int i = 0; i < 6; i++)
            {
                long temp = val % span;
                val /= span;
                if (temp >= 0 && temp <= 9)
                {
                    encodedStr += (char)('0' + temp);
                }
                else if (temp >= 10 && temp <= 35)
                {
                    encodedStr += (char)('a' + (temp - 10));
                }
                else
                {
                    encodedStr += (char)('A' + (temp - 36));
                }
            }
            htLongToShort.Add(longUrl, encodedStr);
            htShortToLong.Add(encodedStr, longUrl);
            result =  @"http://tinyurl.com/" + encodedStr;
            return result;
        }

        // Decodes a shortened URL to its original URL.
        public string decode(string shortUrl)
        {
            shortUrl = shortUrl.Split('/').Last();
            if (htShortToLong.ContainsKey(shortUrl))
            {
                return (string)htShortToLong[shortUrl];
            }
            return null;
        }


    }

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
