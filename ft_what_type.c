#include "libftprintf.h"

char	*ft_what_type(int n, va_list ap, flag_type *flag)
{
	if(n == 1)
	{
		return (ft_itoa(va_arg(ap, int)));
	}
	else if (n == 2)
	{
		return (ft_uitoa(va_arg(ap, int)));
	}
	else if (n == 3)
	{
		return (ft_int_to_octal(va_arg(ap, unsigned int)));
	}
	else if (n == 4)
	{
		return (ft_int_to_hex_low(va_arg(ap, unsigned int)));
	}
	else if (n == 5)
	{
		return (ft_int_to_hex_up(va_arg(ap, unsigned int)));
	}
	else if (n == 6)
	{
		return (ft_chardup(va_arg(ap, int)));
	}
	else if	(n == 7)
	{
		return (ft_strduppf(va_arg(ap, const char*)));
	}
	else if (n == 8)
	{
		return (ft_p_conv(va_arg(ap, long long unsigned int)));
	}
	else if (n == 9)
	{
		return (ft_litoa(va_arg(ap, long int)));
	}
	else if (n == 10)
	{
		return (ft_luitoa(va_arg(ap, long unsigned int)));
	}
	else if (n == 11)
	{
		return (ft_lg_to_octal(va_arg(ap, long unsigned int)));
	}
	else if (n == 12)
	{
		return (ft_lg_to_hex_low(va_arg(ap, long unsigned int)));
	}
	else if (n == 13)
	{
		return (ft_lg_to_hex_up(va_arg(ap, long unsigned int)));
	}
	else if (n == 14)
	{
		return (ft_wintdup(va_arg(ap, wint_t), flag));
	}
	else if (n == 15)
	{
		return (ft_wchardup(va_arg(ap, wchar_t*), flag));
	}
	else if (n == 16)
	{
		return (ft_llitoa(va_arg(ap, long long int)));
	}
	else if (n == 17)
	{
		return (ft_lluitoa(va_arg(ap, long long unsigned int)));
	}
	else if (n == 18)
	{
		return (ft_llg_to_octal(va_arg(ap, long long unsigned int)));
	}
	else if (n == 19)
	{
		return (ft_llg_to_hex_low(va_arg(ap, long long unsigned int)));
	}
	else if (n == 20)
	{
		return (ft_llg_to_hex_up(va_arg(ap, long long unsigned int)));
	}
	else if (n == 21)
	{
		return (ft_sitoa(va_arg(ap, int)));
	}
	else if (n == 22)
	{
		return (ft_suitoa(va_arg(ap, unsigned int)));
	}
	else if (n == 23)
	{
		return (ft_sh_to_octal(va_arg(ap, unsigned int)));
	}
	else if (n == 24)
	{
		return (ft_sh_to_hex_low(va_arg(ap, unsigned int)));
	}
	else if (n == 25)
	{
		return (ft_sh_to_hex_up(va_arg(ap, unsigned int)));
	}
	else if (n == 26)
	{
		return (ft_ctoa(va_arg(ap, int)));
	}
	else if (n == 27)
	{
		return (ft_uctoa(va_arg(ap, unsigned int)));
	}
	else if (n == 28)
	{
		return (ft_ch_to_octal(va_arg(ap, unsigned int)));
	}
	else if (n == 29)
	{
		return (ft_ch_to_hex_low(va_arg(ap, unsigned int)));
	}
	else if (n == 30)
	{
		return (ft_ch_to_hex_up(va_arg(ap, unsigned int)));
	}
	else if (n == 31)
	{
		return (ft_imtoa(va_arg(ap, intmax_t)));
	}
	else if (n == 32)
	{
		return (ft_uimtoa(va_arg(ap, uintmax_t)));
	}
	else if (n == 33)
	{
		return (ft_uim_to_octal(va_arg(ap, uintmax_t)));
	}
	else if (n == 34)
	{
		return (ft_uim_to_hex_low(va_arg(ap, uintmax_t)));
	}
	else if (n == 35)
	{
		return (ft_uim_to_hex_up(va_arg(ap, uintmax_t)));
	}
	else if (n == 36)
	{
		return (ft_ssttoa(va_arg(ap, ssize_t)));
	}
	else if (n == 37)
	{
		return (ft_sttoa(va_arg(ap, size_t)));
	}
	else if (n == 38)
	{
		return (ft_st_to_octal(va_arg(ap, size_t)));
	}
	else if (n == 39)
	{
		return (ft_st_to_hex_low(va_arg(ap, size_t)));
	}
	else if (n == 40)
	{
		return (ft_st_to_hex_up(va_arg(ap, size_t)));
	}
	else if (n == 41)
	{
		return (ft_pc_conv());
	}
	else
		return (NULL);
}
