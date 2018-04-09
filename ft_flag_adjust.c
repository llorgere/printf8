#include <libftprintf.h>
static	flag_type	ft_flag_reset(flag_type flag)
{
//	flag.zero = 0;
	flag.space = 0;
	flag.plus = 0;
//	flag.minus = 0;
	if(flag.preci >= 0)
		flag.width = 0;
	flag.preci = -1;
	flag.dies = 0;
	return (flag);
}
flag_type	ft_flag_adjust(flag_type flag)
{
	if(flag.conv_num == 41)
		return (ft_flag_reset(flag));
	if (flag.zero == 1 && flag.minus == 1)
		flag.zero = 0;
	if (flag.space == 1 && flag.plus == 1)
		flag.space = 0;
	if (flag.dies == 1 && ((flag.conv_num <= 2) ||
			(flag.conv_num <= 10 && flag.conv_num >= 6) ||
			(flag.conv_num <= 17 && flag.conv_num >= 14) ||
			(flag.conv_num <= 22 && flag.conv_num >= 21) ||
			(flag.conv_num <= 27 && flag.conv_num >= 26) ||
			(flag.conv_num <= 32 && flag.conv_num >= 31) ||
			(flag.conv_num <= 37 && flag.conv_num >= 36) ||
			(flag.conv_num >= 41)))
		flag.dies = 0;
	if (flag.plus == 1 && ((flag.conv_num >= 2 && flag.conv_num <= 7) ||
			(flag.conv_num >= 10 && flag.conv_num <= 15) ||
			(flag.conv_num >= 17 && flag.conv_num <= 20) ||
			(flag.conv_num >= 22 && flag.conv_num <= 25) ||
			(flag.conv_num >= 27 && flag.conv_num <= 30) ||
			(flag.conv_num >= 32 && flag.conv_num <= 35) ||
			(flag.conv_num >= 37 && flag.conv_num <= 41)))
		flag.plus = 0;
	if (flag.space == 1 && (flag.conv_num == 0 || (flag.conv_num >= 2 && flag.conv_num <= 7) ||
			(flag.conv_num >= 10 && flag.conv_num <= 15) ||
			(flag.conv_num >= 17 && flag.conv_num <= 20) ||
			(flag.conv_num >= 22 && flag.conv_num <= 25) ||
			(flag.conv_num >= 27 && flag.conv_num <= 30) ||
			(flag.conv_num >= 32 && flag.conv_num <= 35) ||
			(flag.conv_num >= 37 && flag.conv_num <= 41)))
		flag.space = 0;
	if (flag.preci >= 0 && (flag.conv_num == 6 || flag.conv_num == 8 || flag.conv_num == 14))
		flag.preci = -1;
/*	if (flag.zero == 1 && ((flag.conv_num == 6) || (flag.conv_num == 7) ||
			(flag.conv_num == 14) || (flag.conv_num == 15) || flag.preci >= 0))
		flag.zero = 0;
*/	if (flag.zero == 1 && flag.preci >= 0)
		flag.zero = 0;
	return (flag);
}
