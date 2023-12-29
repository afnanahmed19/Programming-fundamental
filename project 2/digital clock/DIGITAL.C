#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdlib.h>
struct BMP
{
	char Type[2];			   	// File type. Set to "BM".
	unsigned long Size;		   	// Size in BYTES of the file.
	unsigned long Reserved;		   	// Reserved. Set to zero.
	unsigned long OffSet;		   	// Offset to the data.
	unsigned long headsize;		  	// Size of rest of header. Set to 40.
	unsigned long Width;		     	// Width of bitmap in pixels.
	unsigned long Height;            	//  Height of bitmap in pixels.
	unsigned int Planes;		   	// Number of Planes. Set to 1.
	unsigned int BitsPerPixel;	   	// Number of Bits per pixels.
	unsigned long Compression;	  	// Compression. Usually set to 0.
	unsigned long SizeImage;	   	// Size in bytes of the bitmap.
	unsigned long XPixelsPreMeter;		// Horizontal pixels per meter.
	unsigned long YPixelsPreMeter;		// Vertical pixels per meter.
	unsigned long ColorsUsed;	   	// Number of colors used.
	unsigned long ColorsImportant; 		// Number of "important" colors.
};
int ShowBMP(int x, int y, char *FileName);
void num(int x, int y, char a);
void shortnum(int x, int y, char a);
void main()
{
	int color, gd = VGA, gm = VGAHI;
	int tme[3], hrs, min, sec, date, year;
	char dt[3], yr[5];
	struct tm tm;
	time_t t;
	t = time(NULL);
	tm = *localtime(&t);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	/*tm.tm_hour = 23;
	tm.tm_min = 59;
	tm.tm_sec = 55;
	tm.tm_wday = 6;
	tm.tm_mday = 31;
	tm.tm_mon = 5;*/
	tm.tm_year = tm.tm_year + 1900;
	while (tm.tm_year)
	{
		while (tm.tm_mon < 12)
		{
			while (tm.tm_mday <= 31)
			{
				cleardevice();
				if (tm.tm_mon == 1)
				{
					// for checking leap year or not
					if (tm.tm_year % 400 == 0 || tm.tm_year % 100 != 0 && tm.tm_year % 4 == 0)
					{
						if (tm.tm_mday > 29)
						{
							break;
						}
					}
					else
					{
						if (tm.tm_mday > 28)
						{
							break;
						}
					}
				}
				else if(tm.tm_year == 3 || tm.tm_year == 5 || tm.tm_year == 8 || tm.tm_year == 10)
				{
					if(tm.tm_year > 30)
					{
						break;
					}
				}
				while (tm.tm_hour < 24)
				{
					while (tm.tm_min != 60)
					{
						if (tm.tm_hour < 12)
						{
							ShowBMP(0, 0, "a.BMP");
							ShowBMP(32, 0, "m.BMP");
						}
						else
						{
							ShowBMP(0, 0, "p.BMP");
							ShowBMP(32, 0, "m.BMP");
						}
						hrs = tm.tm_hour % 12;
						tme[1] = hrs % 10;
						hrs = hrs / 10;
						tme[0] = hrs % 10;
						num(64, 175, tme[0]);
						num(128, 175, tme[1]);
						ShowBMP(208, 175, "colon.BMP");
						min = tm.tm_min;
						tme[1] = min % 10;
						min = min / 10;
						tme[0] = min % 10;
						num(256, 175, tme[0]);
						num(320, 175, tme[1]);
						settextstyle(8, 0, 5);
						switch (tm.tm_wday)
						{
						case 0:
						{
							ShowBMP(448, 0, "s.BMP");
							ShowBMP(480, 0, "u.BMP");
							ShowBMP(512, 0, "n.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 1:
						{
							ShowBMP(448, 0, "m.BMP");
							ShowBMP(480, 0, "o.BMP");
							ShowBMP(512, 0, "n.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 2:
						{
							ShowBMP(416, 0, "t.BMP");
							ShowBMP(448, 0, "u.BMP");
							ShowBMP(480, 0, "e.BMP");
							ShowBMP(512, 0, "s.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 3:
						{
							ShowBMP(352, 0, "w.BMP");
							ShowBMP(384, 0, "e.BMP");
							ShowBMP(416, 0, "d.BMP");
							ShowBMP(448, 0, "n.BMP");
							ShowBMP(480, 0, "e.BMP");
							ShowBMP(512, 0, "s.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 4:
						{
							ShowBMP(384, 0, "t.BMP");
							ShowBMP(416, 0, "h.BMP");
							ShowBMP(448, 0, "u.BMP");
							ShowBMP(480, 0, "r.BMP");
							ShowBMP(512, 0, "s.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 5:
						{
							ShowBMP(448, 0, "f.BMP");
							ShowBMP(480, 0, "r.BMP");
							ShowBMP(512, 0, "i.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						case 6:
						{
							ShowBMP(384, 0, "s.BMP");
							ShowBMP(416, 0, "a.BMP");
							ShowBMP(448, 0, "t.BMP");
							ShowBMP(480, 0, "u.BMP");
							ShowBMP(512, 0, "r.BMP");
							ShowBMP(544, 0, "d.BMP");
							ShowBMP(576, 0, "a.BMP");
							ShowBMP(608, 0, "y.BMP");
							break;
						}
						}
						date = tm.tm_mday;
						dt[1] = date % 10;
						date = date / 10;
						dt[0] = date % 10;
						year = tm.tm_year;
						yr[3] = year % 10;
						year = year / 10;
						yr[2] = year % 10;
						year = year / 10;
						yr[1] = year % 10;
						year = year / 10;
						yr[0] = year % 10;
						switch (tm.tm_mon)
						{
						case 0:
						{
							ShowBMP(0, 416, "j.BMP");
							ShowBMP(32, 416, "a.BMP");
							ShowBMP(64, 416, "n.BMP");
							ShowBMP(96, 416, "u.BMP");
							ShowBMP(128, 416, "a.BMP");
							ShowBMP(160, 416, "r.BMP");
							ShowBMP(192, 416, "y.BMP");
							shortnum(256, 416, dt[0]);
							shortnum(288, 416, dt[1]);
							shortnum(352, 416, yr[0]);
							shortnum(384, 416, yr[1]);
							shortnum(416, 416, yr[2]);
							shortnum(448, 416, yr[3]);
							break;
						}
						case 1:
						{
							ShowBMP(0, 416, "f.BMP");
							ShowBMP(32, 416, "e.BMP");
							ShowBMP(64, 416, "b.BMP");
							ShowBMP(96, 416, "r.BMP");
							ShowBMP(128, 416, "u.BMP");
							ShowBMP(160, 416, "a.BMP");
							ShowBMP(192, 416, "r.BMP");
							ShowBMP(224, 416, "y.BMP");
							shortnum(288, 416, dt[0]);
							shortnum(320, 416, dt[1]);
							shortnum(384, 416, yr[0]);
							shortnum(416, 416, yr[1]);
							shortnum(448, 416, yr[2]);
							shortnum(480, 416, yr[3]);
							break;
						}
						case 2:
						{
							ShowBMP(0, 416, "m.BMP");
							ShowBMP(32, 416, "a.BMP");
							ShowBMP(64, 416, "r.BMP");
							ShowBMP(96, 416, "c.BMP");
							ShowBMP(128, 416, "h.BMP");
							shortnum(192, 416, dt[0]);
							shortnum(224, 416, dt[1]);
							shortnum(288, 416, yr[0]);
							shortnum(320, 416, yr[1]);
							shortnum(352, 416, yr[2]);
							shortnum(384, 416, yr[3]);
							break;
						}
						case 3:
						{

							ShowBMP(0, 416, "a.BMP");
							ShowBMP(32, 416, "p.BMP");
							ShowBMP(64, 416, "r.BMP");
							ShowBMP(96, 416, "i.BMP");
							ShowBMP(128, 416, "l.BMP");
							shortnum(192, 416, dt[0]);
							shortnum(224, 416, dt[1]);
							shortnum(288, 416, yr[0]);
							shortnum(320, 416, yr[1]);
							shortnum(352, 416, yr[2]);
							shortnum(384, 416, yr[3]);
							break;
						}
						case 4:
						{

							ShowBMP(0, 416, "m.BMP");
							ShowBMP(32, 416, "a.BMP");
							ShowBMP(64, 416, "y.BMP");
							shortnum(128, 416, dt[0]);
							shortnum(160, 416, dt[1]);
							shortnum(224, 416, yr[0]);
							shortnum(256, 416, yr[1]);
							shortnum(288, 416, yr[2]);
							shortnum(320, 416, yr[3]);
							break;
						}
						case 5:
						{
							ShowBMP(0, 416, "j.BMP");
							ShowBMP(32, 416, "u.BMP");
							ShowBMP(64, 416, "n.BMP");
							ShowBMP(96, 416, "e.BMP");
							shortnum(160, 416, dt[0]);
							shortnum(192, 416, dt[1]);
							shortnum(256, 416, yr[0]);
							shortnum(288, 416, yr[1]);
							shortnum(320, 416, yr[2]);
							shortnum(352, 416, yr[3]);
							break;
						}
						case 6:
						{
							ShowBMP(0, 416, "j.BMP");
							ShowBMP(32, 416, "u.BMP");
							ShowBMP(64, 416, "l.BMP");
							ShowBMP(96, 416, "y.BMP");
							shortnum(160, 416, dt[0]);
							shortnum(192, 416, dt[1]);
							shortnum(256, 416, yr[0]);
							shortnum(288, 416, yr[1]);
							shortnum(320, 416, yr[2]);
							shortnum(352, 416, yr[3]);
							break;
						}
						case 7:
						{

							ShowBMP(0, 416, "a.BMP");
							ShowBMP(32, 416, "u.BMP");
							ShowBMP(64, 416, "g.BMP");
							ShowBMP(92, 416, "u.BMP");
							ShowBMP(128, 416, "s.BMP");
							ShowBMP(160, 416, "t.BMP");
							shortnum(224, 416, dt[0]);
							shortnum(256, 416, dt[1]);
							shortnum(320, 416, yr[0]);
							shortnum(352, 416, yr[1]);
							shortnum(384, 416, yr[2]);
							shortnum(416, 416, yr[3]);
							break;
						}
						case 8:
						{

							ShowBMP(0, 416, "s.BMP");
							ShowBMP(32, 416, "e.BMP");
							ShowBMP(64, 416, "p.BMP");
							ShowBMP(92, 416, "t.BMP");
							ShowBMP(128, 416, "e.BMP");
							ShowBMP(160, 416, "m.BMP");
							ShowBMP(192, 416, "b.BMP");
							ShowBMP(224, 416, "e.BMP");
							ShowBMP(256, 416, "r.BMP");
							shortnum(320, 416, dt[0]);
							shortnum(352, 416, dt[1]);
							shortnum(416, 416, yr[0]);
							shortnum(448, 416, yr[1]);
							shortnum(480, 416, yr[2]);
							shortnum(512, 416, yr[3]);
							break;
						}
						case 9:
						{
							ShowBMP(0, 416, "o.BMP");
							ShowBMP(32, 416, "c.BMP");
							ShowBMP(64, 416, "t.BMP");
							ShowBMP(92, 416, "o.BMP");
							ShowBMP(128, 416, "b.BMP");
							ShowBMP(160, 416, "e.BMP");
							ShowBMP(192, 416, "r.BMP");
							shortnum(256, 416, dt[0]);
							shortnum(288, 416, dt[1]);
							shortnum(352, 416, yr[0]);
							shortnum(384, 416, yr[1]);
							shortnum(416, 416, yr[2]);
							shortnum(448, 416, yr[3]);
							break;
						}
						case 10:
						{
							ShowBMP(0, 416, "n.BMP");
							ShowBMP(32, 416, "o.BMP");
							ShowBMP(64, 416, "v.BMP");
							ShowBMP(96, 416, "e.BMP");
							ShowBMP(128, 416, "m.BMP");
							ShowBMP(160, 416, "b.BMP");
							ShowBMP(192, 416, "e.BMP");
							ShowBMP(224, 416, "r.BMP");
							shortnum(288, 416, dt[0]);
							shortnum(320, 416, dt[1]);
							shortnum(384, 416, yr[0]);
							shortnum(416, 416, yr[1]);
							shortnum(448, 416, yr[2]);
							shortnum(480, 416, yr[3]);
							break;
						}
						case 11:
						{
							ShowBMP(0, 416, "d.BMP");
							ShowBMP(32, 416, "e.BMP");
							ShowBMP(64, 416, "c.BMP");
							ShowBMP(96, 416, "e.BMP");
							ShowBMP(128, 416, "m.BMP");
							ShowBMP(160, 416, "b.BMP");
							ShowBMP(192, 416, "e.BMP");
							ShowBMP(224, 416, "r.BMP");
							shortnum(288, 416, dt[0]);
							shortnum(320, 416, dt[1]);
							shortnum(384, 416, yr[0]);
							shortnum(416, 416, yr[1]);
							shortnum(448, 416, yr[2]);
							shortnum(480, 416, yr[3]);
						}
						}
						while (tm.tm_sec != 60)
						{
							sec = tm.tm_sec;
							tme[1] = sec % 10;
							sec = sec / 10;
							tme[0] = sec % 10;
							ShowBMP(400, 175, "colon.BMP");
							num(448, 175, tme[0]);
							num(512, 175, tme[1]);
							delay(900);
							if (kbhit())
							{
								exit(1);
							}
							tm.tm_sec++;
						}
						tm.tm_sec = 0;
						tm.tm_min++;
					}
					tm.tm_min = 0;
					tm.tm_hour++;
				}
				tm.tm_hour = 0;
				tm.tm_mday++;
				tm.tm_wday++;
				if (tm.tm_wday == 7)
				{
					tm.tm_wday = 0;
				}
			}
			tm.tm_mday = 1;
			tm.tm_mon++;
		}
		tm.tm_mon = 0;
		tm.tm_year++;
	}
	closegraph();
}
int ShowBMP(int x, int y, char *FileName)
{
	int b, a;
	struct BMP Obj;

	unsigned char *Datas;
	int in = 0;
	unsigned char c = 0;
	FILE *fp;
	fp = fopen(FileName, "rb");
	if (!fp)
	{
		printf("Error : Unable to open file ..");
		exit(0);
	}

	fread(&Obj, sizeof(Obj), 1, fp);
	if (Obj.BitsPerPixel != 4) // This isn't a 16 color bmp we can read;
	{
		fclose(fp);
		printf("Error : File format not supported ..");
		exit(0);
	};
	fseek(fp, Obj.OffSet, SEEK_SET);
	Datas = (unsigned char *)calloc(Obj.Width / 2 + 1, sizeof(unsigned char));
	for (b = Obj.Height; b >= 0; b--)
	{
		fread(Datas, sizeof(unsigned char), Obj.Width / 2, fp);
		c = 0;
		in = 0;
		for (a = 0; a <= Obj.Width; a += 2)
		{
			c = (Datas[in] | 0x00) >> 4;
			putpixel(a + x, b + y, c);
			c = (Datas[in] | 0xF0) & 0x0F;
			putpixel(a + 1 + x, b + y, c);
			in++;
		}
	}
	free(Datas);
	fclose(fp);
	return 1;
}
void num(int x, int y, char ch)
{
	switch (ch)
	{
	case 0:
		ShowBMP(x, y, "0.BMP");
		break;
	case 1:
		ShowBMP(x, y, "1.BMP");
		break;
	case 2:
		ShowBMP(x, y, "2.BMP");
		break;
	case 3:
		ShowBMP(x, y, "3.BMP");
		break;
	case 4:
		ShowBMP(x, y, "4.BMP");
		break;
	case 5:
		ShowBMP(x, y, "5.BMP");
		break;
	case 6:
		ShowBMP(x, y, "6.BMP");
		break;
	case 7:
		ShowBMP(x, y, "7.BMP");
		break;
	case 8:
		ShowBMP(x, y, "8.BMP");
		break;
	case 9:
		ShowBMP(x, y, "9.BMP");
		break;
	}
}
void shortnum(int x, int y, char ch)
{
	switch (ch)
	{
	case 0:
		ShowBMP(x, y, "zero.BMP");
		break;
	case 1:
		ShowBMP(x, y, "one.BMP");
		break;
	case 2:
		ShowBMP(x, y, "two.BMP");
		break;
	case 3:
		ShowBMP(x, y, "three.BMP");
		break;
	case 4:
		ShowBMP(x, y, "four.BMP");
		break;
	case 5:
		ShowBMP(x, y, "five.BMP");
		break;
	case 6:
		ShowBMP(x, y, "six.BMP");
		break;
	case 7:
		ShowBMP(x, y, "seven.BMP");
		break;
	case 8:
		ShowBMP(x, y, "eight.BMP");
		break;
	case 9:
		ShowBMP(x, y, "nine.BMP");
		break;
	}
}
// struct tm {
//    int tm_sec;         /* seconds,  range 0 to 59          */
//    int tm_min;         /* minutes, range 0 to 59           */
//    int tm_hour;        /* hours, range 0 to 23             */
//    int tm_mday;        /* day of the month, range 1 to 31  */
//    int tm_mon;         /* month, range 0 to 11             */
//    int tm_year;        /* The number of years since 1900   */
//    int tm_wday;        /* day of the week, range 0 to 6    */
//    int tm_yday;        /* day in the year, range 0 to 365  */
//    int tm_isdst;       /* daylight saving time             */
// };

// for printing week days