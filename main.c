/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:27:57 by cduvivie          #+#    #+#             */
/*   Updated: 2020/03/02 14:38:11 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>
#include "assert.h"


int		main()
{

	int original;
	int myfunc;

	/*
	**	Percent conversion %
	*/

	printf("=============== BASIC INPUTS ================\n");

	original = printf("Hello, World!\n");
	myfunc = ft_printf("Hello, World!\n");
	
	printf("\n");
	
	original = printf("My email address: school19[%c]gmail.com\n", '@');
	myfunc = ft_printf("My email address: school19[%c]gmail.com\n", '@');
	
	printf("\n");

	original = printf("[%s]\n", "This is a string");
	myfunc = ft_printf("[%s]\n", "This is a string");
	
	printf("\n");
	
	unsigned long *b;
	unsigned long a;
	a = 10;
	b = &a;
	
	original = printf("[%p]\n", b);
	myfunc = ft_printf("[%p]\n", b);
	
	printf("\n");
	
	original = printf("I was born in [%d], the [%i]th of Decembre, at [%d]PM\n", 2020, -2147483647, 0);
	myfunc = ft_printf("I was born in [%d], the [%i]th of Decembre, at [%d]PM\n", 2020, -2147483647, 0);	
	
	printf("\n");

	original = printf("unsigned integer: [%u]\n", 4294967295);
	myfunc = ft_printf("unsigned integer: [%u]\n", 4294967295);
	
	printf("\n");

	// original = printf("In hexadecimal: [%lx]\n", 4483234592);
	// myfunc = ft_printf("In hexadecimal: [%x]\n", 4483234592);
	// 
	// printf("\n");

	original = printf("In hexadecimal: [%X]\n", 254);
	myfunc = ft_printf("In hexadecimal: [%X]\n", 254);
	
	printf("\n");

	original = printf("0.5 equals 50[%%]\n");
	myfunc = ft_printf("0.5 equals 50[%%]\n");
	
	printf("\n");
	
	
	// original = printf("0.5 equals 50%%, and 0.2 equals 20\% \n");
	// myfunc = ft_printf("0.5 equals 50%%, and 0.2 equals 20\% \n");
	// 
	// printf("\n");

	printf("=============== Weird Inputs ================\n");
	
	// printf("orginal = %d\n", original);
	// printf("myfunc = %d\n", myfunc);
	
	original = printf("[%c]\n", '0');
	myfunc = ft_printf("[%c]\n", '0');
	
	printf("\n");

	original = printf("real:Hey [%c]\n", 0);
	myfunc = ft_printf("mine:Hey [%c]\n", 0);
	
	printf("\n");

	original = printf("Hey [%c]\n", 0);
	myfunc = ft_printf("Hey [%c]\n", 0);
	
	printf("\n");

	original = printf("[%s]\n", NULL);
	myfunc = ft_printf("[%s]\n", NULL);
	
	printf("\n");

	original = printf("origin:![%40c]!\n", 0);
	myfunc = ft_printf("mineft:![%40c]!\n", 0);
	
	printf("\n");

	original = printf("or[%-5c]", 0);
	printf("\n");
	myfunc = ft_printf("me[%-5c]", 0);
	printf("\n");
	
	printf("\n");

	original = printf("or[42%20c42]\n", 0);
	myfunc = ft_printf("me[42%20c42]\n", 0);
	
	printf("\n");

	original = printf("(null)\n", 0);
	myfunc = ft_printf("(null)\n", 0);
	
	printf("\n");

	printf("[");
	original = printf("%");
	printf("]");
	printf("\n");
	
	printf("[");
	myfunc = ft_printf("%");
	printf("]");
	printf("\n");
	
	printf("orginal = %d\n", original);
	printf("myfunc = %d\n", myfunc);
	
	printf("\n");

	/*
	**	The Width Option
	*/
	printf("=============== The Width Option ================\n");

	original = printf("100/10 equals [%5d] !\n", 10);
	myfunc = ft_printf("100/10 equals [%5d] !\n", 10);
	
	printf("\n");

	original = printf("[%5d]\n", -7);
	myfunc = ft_printf("[%5d]\n", -7);
	
	printf("\n");

	original = printf("[%5d]\n", 1560133615);
	myfunc = ft_printf("[%5d]\n", 1560133615);
	
	printf("\n");
	
	original = printf("[%5d]\n", -2035065302);
	myfunc = ft_printf("[%5d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%5s]\n", "");
	myfunc = ft_printf("[%5s]\n", "");
	
	printf("\n");

	original = printf("[%5s]\n", "a");
	myfunc = ft_printf("[%5s]\n", "a");
	
	printf("\n");
	
	original = printf("[%5s]\n", "ab");
	myfunc = ft_printf("[%5s]\n", "ab");
	
	printf("\n");

	original = printf("[%5s]\n", "abcdefg");
	myfunc = ft_printf("[%5s]\n", "abcdefg");
	
	printf("\n");

	original = printf("[%5p]\n", b);
	myfunc = ft_printf("[%5p]\n", b);
	
	printf("\n");

	original = printf("[%10p]\n", b);
	myfunc = ft_printf("[%10p]\n", b);
	
	printf("\n");

	original = printf("[%*p]\n", 20, b);
	myfunc = ft_printf("[%*p]\n", 20, b);
	
	printf("\n");

	original = printf("[%5x]\n", 0);
	myfunc = ft_printf("[%5x]\n", 0);
	
	printf("\n");

	original = printf("[%9x]\n", 123456789);
	myfunc = ft_printf("[%9x]\n", 123456789);
	
	printf("\n");

	printf("=============== The Justify Option ================\n");

	original = printf("100/10 equals [%-5d] !\n", 10);
	myfunc = ft_printf("100/10 equals [%-5d] !\n", 10);
	
	printf("\n");

	original = printf("[%-5d]\n", -7);
	myfunc = ft_printf("[%-5d]\n", -7);
	
	printf("\n");

	original = printf("[%-5d]\n", 1560133615);
	myfunc = ft_printf("[%-5d]\n", 1560133615);
	
	printf("\n");

	original = printf("[%-19d]\n", -2035065302);
	myfunc = ft_printf("[%-19d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%-5s]\n", "");
	myfunc = ft_printf("[%-5s]\n", "");
	
	printf("\n");

	original = printf("[%-5s]\n", "a");
	myfunc = ft_printf("[%-5s]\n", "a");
	
	printf("\n");

	original = printf("[%-5s]\n", "ab");
	myfunc = ft_printf("[%-5s]\n", "ab");
	
	printf("\n");

	original = printf("[%-5s]\n", "abcdefg");
	myfunc = ft_printf("[%-5s]\n", "abcdefg");
	
	printf("\n");

	original = printf("[%-*s]\n", 5, "a");
	myfunc = ft_printf("[%-*s]\n", 5, "a");
	
	printf("\n");

	original = printf("[%-*s]\n", 5, "ab");
	myfunc = ft_printf("[%-*s]\n", 5, "ab");
	
	printf("\n");

	original = printf("[%-*s]\n", 5, "abcdefg");
	myfunc = ft_printf("[%-*s]\n", 5, "abcdefg");
	
	printf("\n");

	original = printf("[%-5p]\n", b);
	myfunc = ft_printf("[%-5p]\n", b);
	
	printf("\n");

	original = printf("[%-10p]\n", b);
	myfunc = ft_printf("[%-10p]\n", b);
	
	printf("\n");

	original = printf("[%-*p]\n", 20, b);
	myfunc = ft_printf("[%-*p]\n", 20, b);
	
	printf("\n");

	original = printf("[%-5x]\n", 0);
	myfunc = ft_printf("[%-5x]\n", 0);
	
	printf("\n");

	original = printf("[%-9x]\n", 123456789);
	myfunc = ft_printf("[%-9x]\n", 123456789);
	
	printf("\n");

	printf("=============== The Zero-Fill Option ================\n");

	original = printf("100/10 equals [%05d] !\n", 10);
	myfunc = ft_printf("100/10 equals [%05d] !\n", 10);
	
	printf("\n");
	
	original = printf("[%05d]\n", -7);
	myfunc = ft_printf("[%05d]\n", -7);
	
	printf("\n");

	original = printf("[%05d]\n", 1560133615);
	myfunc = ft_printf("[%05d]\n", 1560133615);
	
	printf("\n");

	original = printf("[%020d]\n", -2035065302);
	myfunc = ft_printf("[%020d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%05x]\n", 0);
	myfunc = ft_printf("[%05x]\n", 0);
	
	printf("\n");

	original = printf("[%09x]\n", 123456789);
	myfunc = ft_printf("[%09x]\n", 123456789);
	
	printf("\n");

	original = printf("%+09s", "hi low");
	printf("\n");
	myfunc = ft_printf("%+09s", "hi low");
	printf("\n");
	
	printf("\n");

	// printf("=============== The Zero-Fill + Justify Option ================\n");
	
	// printf("[%-05d]\n", -7);
	// ft_printf("[%-05d]\n", -7);

	printf("=============== Precision Option ================\n");

	original = printf("[%.5d]\n", 3);
	myfunc = ft_printf("[%.5d]\n", 3);
	
	printf("\n");
	
	original = printf("[%.5d]\n", -7);
	myfunc = ft_printf("[%.5d]\n", -7);
	
	printf("\n");

	original = printf("[%.0d]\n", 0);
	myfunc = ft_printf("[%.0d]\n", 0);
	
	printf("\n");

	original = printf("[%.d]\n", 6);
	myfunc = ft_printf("[%.d]\n", 6);
	
	printf("\n");

	original = printf("[%.5d]\n", 123456789);
	myfunc = ft_printf("[%.5d]\n", 123456789);
	
	printf("\n");
	
	original = printf("[%.5s]\n", "abc");
	myfunc = ft_printf("[%.5s]\n", "abc");
	
	printf("\n");

	original = printf("[%.5s]\n", "abcde");
	myfunc = ft_printf("[%.5s]\n", "abcde");
	
	printf("\n");

	original = printf("[%.5s]\n", "abcdefghijk");
	myfunc = ft_printf("[%.5s]\n", "abcdefghijk");
	
	printf("\n");

	original = printf("[%.10u]\n", 21);
	myfunc = ft_printf("[%.10u]\n", 21);
	
	printf("\n");

	original = printf("[%.x]\n", 12);
	myfunc = ft_printf("[%.x]\n", 12);
	
	printf("\n");
	
	original = printf("[%.2X]\n", 0x11aabbcc);
	myfunc = ft_printf("[%.2X]\n", 0x11aabbcc);
	
	printf("\n");

	original = printf("[%.*d]\n", 10, -7);
	myfunc = ft_printf("[%.*d]\n", 10, -7);
	
	printf("\n");

	original = printf("[%+.0i]", 0);
	printf("\n");
	myfunc = ft_printf("[%+.0i]", 0);
	printf("\n");
	
	printf("\n");

	// original = printf("[%.*3$d]\n", -7, 9, 10);



	printf("=============== Min Field Width + Precision ================\n");

	original = printf("[%4.8s]\n", "abc");
	myfunc = ft_printf("[%4.8s]\n", "abc");
	
	printf("\n");
	
	original = printf("[%4.8s]\n", "abcde");
	myfunc = ft_printf("[%4.8s]\n", "abcde");
	
	printf("\n");

	original = printf("[%4.8s]\n", "abcdefghijk");
	myfunc = ft_printf("[%4.8s]\n", "abcdefghijk");
	
	printf("\n");

	original = printf("[%10.5d]\n", -7);
	myfunc = ft_printf("[%10.5d]\n", -7);
	
	printf("\n");

	printf("=============== LEFT JUST + Min Field Width + Precision ================\n");

	original = printf("[%-10.5d]\n", -7);
	myfunc = ft_printf("[%-10.5d]\n", -7);
	
	printf("\n");

	original = printf("[%-10.5d]\n", 7);
	myfunc = ft_printf("[%-10.5d]\n", 7);
	
	printf("\n");

	original = printf("[%-3.5d]\n", -12345);
	myfunc = ft_printf("[%-3.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%-8.5d]\n", -12345);
	myfunc = ft_printf("[%-8.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%-4.8s]\n", "");
	myfunc = ft_printf("[%-4.8s]\n", "");
	
	printf("\n");
	
	original = printf("[%-4.8s]\n", "abc");
	myfunc = ft_printf("[%-4.8s]\n", "abc");
	
	printf("\n");
	
	original = printf("[%-4.8s]\n", "abcde");
	myfunc = ft_printf("[%-4.8s]\n", "abcde");
	
	printf("\n");

	original = printf("[%-4.8s]\n", "abcdefghijk");
	myfunc = ft_printf("[%-4.8s]\n", "abcdefghijk");
	
	printf("\n");

	printf("=============== FROM UNIT TESTS ================\n");
	original = printf("neg8 [%*.*s]\n", -30, 15, "coucou");
	myfunc = ft_printf("neg8 [%*.*s]\n", -30, 15, "coucou");
	
	printf("\n");


	printf("=============== PERCENT TESTS ================\n");
	original = printf("[%.0%]\n");
	myfunc = ft_printf("[%.0%]\n");
	
	printf("\n");

	original = printf("[%-5%]\n");
	myfunc = ft_printf("[%-5%]\n");
	
	printf("\n");

	original = printf("[%+%]\n");
	myfunc = ft_printf("[%+%]\n");
	
	printf("\n");

	original = printf("[%020%]\n");
	myfunc = ft_printf("[%020%]\n");
	
	printf("\n");

	original = printf("[%0+20%]\n");
	myfunc = ft_printf("[%0+20%]\n");
	
	printf("\n");

	original = printf("[%020.%]\n");
	myfunc = ft_printf("[%020.%]\n");
	
	printf("\n");

	original = printf("[%0+20.122%]\n");
	myfunc = ft_printf("[%0+20.122%]\n");
	
	printf("\n");

	printf("======================================\n");
	printf("=============== BONUS ================\n");
	printf("======================================\n\n");

	printf("=============== PLUS SIGN TESTS ================\n");
	
	original = printf("[%+d]\n", 0);
	myfunc = ft_printf("[%+d]\n", 0);
	
	printf("\n");
	
	original = printf("[%+d]\n", -7);
	myfunc = ft_printf("[%+d]\n", -7);
	
	printf("\n");

	original = printf("[%+d]\n", 42);
	myfunc = ft_printf("[%+d]\n", 42);
	
	printf("\n");

	original = printf("[%+5d]\n", 0);
	myfunc = ft_printf("[%+5d]\n", 0);
	
	printf("\n");

	original = printf("[%+5d]\n", -7);
	myfunc = ft_printf("[%+5d]\n", -7);
	
	printf("\n");

	original = printf("[%+5d]\n", 1560133635);
	myfunc = ft_printf("[%+5d]\n", 1560133635);
	
	printf("\n");

	original = printf("[%+5d]\n", -2035065302);
	myfunc = ft_printf("[%+5d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%-+5d]\n", 0);
	myfunc = ft_printf("[%-+5d]\n", 0);
	
	printf("\n");

	original = printf("[%-+5d]\n", -7);
	myfunc = ft_printf("[%-+5d]\n", -7);
	
	printf("\n");

	original = printf("[%-+5d]\n", 1560133635);
	myfunc = ft_printf("[%-+5d]\n", 1560133635);
	
	printf("\n");

	original = printf("[%-+5d]\n", -2035065302);
	myfunc = ft_printf("[%-+5d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%+05d]\n", 0);
	myfunc = ft_printf("[%+05d]\n", 0);
	
	printf("\n");

	original = printf("[%+05d]\n", -7);
	myfunc = ft_printf("[%+05d]\n", -7);
	
	printf("\n");

	original = printf("[%+05d]\n", 1560133635);
	myfunc = ft_printf("[%+05d]\n", 1560133635);
	
	printf("\n");

	original = printf("[%+05d]\n", -2035065302);
	myfunc = ft_printf("[%+05d]\n", -2035065302);
	
	printf("\n");

	printf("=============== SPACE TESTS ================\n");
	
	original = printf("[% -d]\n", 0);
	myfunc = ft_printf("[% -d]\n", 0);
	
	printf("\n");
	
	original = printf("[% d]\n", 0);
	myfunc = ft_printf("[% d]\n", 0);
	
	printf("\n");

	original = printf("[% 5d]\n", 0);
	myfunc = ft_printf("[% 5d]\n", 0);
	
	printf("\n");

	original = printf("[% 5d]\n", -7);
	myfunc = ft_printf("[% 5d]\n", -7);
	
	printf("\n");

	original = printf("[% 5d]\n", 1560133635);
	myfunc = ft_printf("[% 5d]\n", 1560133635);
	
	printf("\n");

	original = printf("[% 5d]\n", -2035065302);
	myfunc = ft_printf("[% 5d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%- 5d]\n", 0);
	myfunc = ft_printf("[%- 5d]\n", 0);
	
	printf("\n");

	original = printf("[%- 5d]\n", -7);
	myfunc = ft_printf("[%- 5d]\n", -7);
	
	printf("\n");

	original = printf("[%- 5d]\n", 1560133635);
	myfunc = ft_printf("[%- 5d]\n", 1560133635);
	
	printf("\n");

	original = printf("[%- 5d]\n", -2035065302);
	myfunc = ft_printf("[%- 5d]\n", -2035065302);
	
	printf("\n");

	original = printf("[% 05d]\n", 0);
	myfunc = ft_printf("[% 05d]\n", 0);
	
	printf("\n");

	original = printf("[% 05d]\n", -7);
	myfunc = ft_printf("[% 05d]\n", -7);
	
	printf("\n");

	original = printf("[% 05d]\n", 1560133635);
	myfunc = ft_printf("[% 05d]\n", 1560133635);
	
	printf("\n");

	original = printf("[% 05d]\n", -2035065302);
	myfunc = ft_printf("[% 05d]\n", -2035065302);
	
	printf("\n");

	original = printf("[% 05.7d]\n", 0);
	myfunc = ft_printf("[% 05.7d]\n", 0);
	
	printf("\n");

	original = printf("[% 05.3d]\n", -7);
	myfunc = ft_printf("[% 05.3d]\n", -7);
	
	printf("\n");

	original = printf("[% 05.16d]\n", 1560133635);
	myfunc = ft_printf("[% 05.16d]\n", 1560133635);
	
	printf("\n");

	original = printf("[% 05.8d]\n", -2035065302);
	myfunc = ft_printf("[% 05.8d]\n", -2035065302);
	
	printf("\n");

	printf("=============== xX format TESTS ================\n");

	original = printf("[%x]\n", -2147483648);
	myfunc = ft_printf("[%x]\n", -2147483648);
	
	printf("\n");

	original = printf("[%X]\n", -2147483648);
	myfunc = ft_printf("[%X]\n", -2147483648);
	
	printf("\n");

	original = printf("[%.*d]\n", 10, 42);
	myfunc = ft_printf("[%.*d]\n", 10, 42);
	
	printf("\n");
	
	original = printf("{%.*d}\n", -5, 42);
	myfunc = ft_printf("{%.*d}\n", -5, 42);
	
	printf("\n");

	original = printf("[%.5d]\n", -2372);
	myfunc = ft_printf("[%.5d]\n", -2372);
	
	printf("\n");

	printf("=============== ' THOUSANDS SEPERATOR TESTS ================\n");
	
	setlocale(LC_NUMERIC, "");
	original = printf("[%'d]\n", -0);
	myfunc = ft_printf("[%'d]\n", -0);
	
	printf("\n");

	original = printf("[%+'d]\n", 1234567890);
	myfunc = ft_printf("[%+'d]\n", 1234567890);
	
	printf("\n");

	original = printf("[% 'd]\n", 1234567890);
	myfunc = ft_printf("[% 'd]\n", 1234567890);
	
	printf("\n");

	original = printf("[%'20d]\n", 1234567890);
	myfunc = ft_printf("[%'20d]\n", 1234567890);
	
	printf("\n");

	original = printf("[%-'20d]\n", 1234567890);
	myfunc = ft_printf("[%-'20d]\n", 1234567890);
	
	printf("\n");

	original = printf("[%-'20.7d]\n", 1234567890);
	myfunc = ft_printf("[%-'20.7d]\n", 1234567890);
	
	printf("\n");

	original = printf("[%'d]\n", 0);
	myfunc = ft_printf("[%'d]\n", 0);
	
	printf("\n");

	original = printf("[%'d]\n", -7);
	myfunc = ft_printf("[%'d]\n", -7);
	
	printf("\n");

	original = printf("[%'d]\n", 1560133635);
	myfunc = ft_printf("[%'d]\n", 1560133635);
	
	printf("\n");

	original = printf("[%'d]\n", -2035065302);
	myfunc = ft_printf("[%'d]\n", -2035065302);
	
	printf("\n");

	original = printf("[%'d]\n", 380236);
	myfunc = ft_printf("[%'d]\n", 380236);
	
	printf("\n");

	original = printf("[%'+d]\n", 380236);
	myfunc = ft_printf("[%'+d]\n", 380236);
	
	printf("\n");

	original = printf("[%'d]\n", -380236);
	myfunc = ft_printf("[%'d]\n", -380236);
	
	printf("\n");

	original = printf("[%'d]\n", 38026);
	myfunc = ft_printf("[%'d]\n", 38026);
	
	printf("\n");
	
	original = printf("[%'-27d]\n", 32480236);
	myfunc = ft_printf("[%'-27d]\n", 32480236);
	
	printf("\n");

	original = printf("[%'-+27d]\n", 32480236);
	myfunc = ft_printf("[%'-+27d]\n", 32480236);
	
	printf("\n");

	original = printf("[%'-+.73d]\n", 32480236);
	myfunc = ft_printf("[%'-+.73d]\n", 32480236);
	
	printf("\n");
	
	original = printf("[%'-.73d]\n", 32480236);
	myfunc = ft_printf("[%'-.73d]\n", 32480236);
	
	printf("\n");
	
	original = printf("[%'-27.73d]\n", 32480236);
	myfunc = ft_printf("[%'-27.73d]\n", 32480236);
	
	printf("\n");

	printf("=============== p TESTS ================\n");
	
	original = printf("[%.0p], [%.p], [%p]\n", 0, 0, 0);
	myfunc = ft_printf("[%.0p], [%.p], [%p]\n", 0, 0, 0);
	
	printf("\n");

	original = printf("[%.5p]\n", 0);
	myfunc = ft_printf("[%.5p]\n", 0);
	
	printf("\n");
	
	original = printf("[%.5p], [%.p], [%5p]\n", 987654, 987654, 987654);
	myfunc = ft_printf("[%.5p], [%.p], [%5p]\n", 987654, 987654, 987654);
	
	printf("\n");

	original = printf("[%2.9p]\n", 1234);
	myfunc = ft_printf("[%2.9p]\n", 1234);
	
	printf("\n");

	printf("=============== format[d] + Min Field Width + Precision ================\n");

	original = printf("[%3.5d]\n", 0);
	myfunc = ft_printf("[%3.5d]\n", 0);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", 0);
	myfunc = ft_printf("[%5.5d]\n", 0);
	
	printf("\n");

	original = printf("[%10.5d]\n", 0);
	myfunc = ft_printf("[%10.5d]\n", 0);
	
	printf("\n");
	
	original = printf("[%3.5d]\n", 7);
	myfunc = ft_printf("[%3.5d]\n", 7);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", 7);
	myfunc = ft_printf("[%5.5d]\n", 7);
	
	printf("\n");

	original = printf("[%10.5d]\n", 7);
	myfunc = ft_printf("[%10.5d]\n", 7);
	
	printf("\n");

	original = printf("[%3.5d]\n", 12345);
	myfunc = ft_printf("[%3.5d]\n", 12345);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", 12345);
	myfunc = ft_printf("[%5.5d]\n", 12345);
	
	printf("\n");

	original = printf("[%10.5d]\n", 12345);
	myfunc = ft_printf("[%10.5d]\n", 12345);
	
	printf("\n");

	original = printf("[%3.5d]\n", 12345678);
	myfunc = ft_printf("[%3.5d]\n", 12345678);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", 12345678);
	myfunc = ft_printf("[%5.5d]\n", 12345678);
	
	printf("\n");

	original = printf("[%10.5d]\n", 12345678);
	myfunc = ft_printf("[%10.5d]\n", 12345678);
	
	printf("\n");

	original = printf("[%3.5d]\n", -7);
	myfunc = ft_printf("[%3.5d]\n", -7);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", -7);
	myfunc = ft_printf("[%5.5d]\n", -7);
	
	printf("\n");

	original = printf("[%10.5d]\n", -7);
	myfunc = ft_printf("[%10.5d]\n", -7);
	
	printf("\n");

	original = printf("[%3.5d]\n", -12345);
	myfunc = ft_printf("[%3.5d]\n", -12345);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", -12345);
	myfunc = ft_printf("[%5.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%10.5d]\n", -12345);
	myfunc = ft_printf("[%10.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%3.5d]\n", -12345678);
	myfunc = ft_printf("[%3.5d]\n", -12345678);
	
	printf("\n");
	
	original = printf("[%5.5d]\n", -12345678);
	myfunc = ft_printf("[%5.5d]\n", -12345678);
	
	printf("\n");

	original = printf("[%10.5d]\n", -12345678);
	myfunc = ft_printf("[%10.5d]\n", -12345678);
	
	printf("\n");
	
	original = printf("{%05.*d}\n", -15, 42);
	myfunc = ft_printf("{%05.*d}\n", -15, 42);
	
	printf("\n");

	printf("=============== format[d] + ZeroPadding + Min Field Width + Precision ================\n");

	original = printf("[%03.5d]\n", 0);
	myfunc = ft_printf("[%03.5d]\n", 0);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", 0);
	myfunc = ft_printf("[%05.5d]\n", 0);
	
	printf("\n");

	original = printf("[%010.5d]\n", 0);
	myfunc = ft_printf("[%010.5d]\n", 0);
	
	printf("\n");
	
	original = printf("[%03.5d]\n", 7);
	myfunc = ft_printf("[%03.5d]\n", 7);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", 7);
	myfunc = ft_printf("[%05.5d]\n", 7);
	
	printf("\n");

	original = printf("[%010.5d]\n", 7);
	myfunc = ft_printf("[%010.5d]\n", 7);
	
	printf("\n");

	original = printf("[%03.5d]\n", 12345);
	myfunc = ft_printf("[%03.5d]\n", 12345);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", 12345);
	myfunc = ft_printf("[%05.5d]\n", 12345);
	
	printf("\n");

	original = printf("[%010.5d]\n", 12345);
	myfunc = ft_printf("[%010.5d]\n", 12345);
	
	printf("\n");

	original = printf("[%03.5d]\n", 12345678);
	myfunc = ft_printf("[%03.5d]\n", 12345678);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", 12345678);
	myfunc = ft_printf("[%05.5d]\n", 12345678);
	
	printf("\n");

	original = printf("[%010.5d]\n", 12345678);
	myfunc = ft_printf("[%010.5d]\n", 12345678);
	
	printf("\n");

	original = printf("[%03.5d]\n", -7);
	myfunc = ft_printf("[%03.5d]\n", -7);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", -7);
	myfunc = ft_printf("[%05.5d]\n", -7);
	
	printf("\n");

	original = printf("[%010.5d]\n", -7);
	myfunc = ft_printf("[%010.5d]\n", -7);
	
	printf("\n");

	original = printf("[%03.5d]\n", -12345);
	myfunc = ft_printf("[%03.5d]\n", -12345);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", -12345);
	myfunc = ft_printf("[%05.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%010.5d]\n", -12345);
	myfunc = ft_printf("[%010.5d]\n", -12345);
	
	printf("\n");

	original = printf("[%03.5d]\n", -12345678);
	myfunc = ft_printf("[%03.5d]\n", -12345678);
	
	printf("\n");
	
	original = printf("[%05.5d]\n", -12345678);
	myfunc = ft_printf("[%05.5d]\n", -12345678);
	
	printf("\n");

	original = printf("[%010.5d]\n", -12345678);
	myfunc = ft_printf("[%010.5d]\n", -12345678);
	
	printf("\n");

	printf("=============== SHARP # TESTS ================\n");
	
	original = printf("[%#x]\n", 0);
	myfunc = ft_printf("[%#x]\n", 0);
	
	printf("\n");

	original = printf("[%#x]\n", -7);
	myfunc = ft_printf("[%#x]\n", -7);
	
	printf("\n");

	original = printf("[%#x]\n", 1560133635);
	myfunc = ft_printf("[%#x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#x]\n", -2035065302);
	myfunc = ft_printf("[%#x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#X]\n", 0);
	myfunc = ft_printf("[%#X]\n", 0);
	
	printf("\n");

	original = printf("[%#X]\n", 3);
	myfunc = ft_printf("[%#X]\n", 3);
	
	printf("\n");

	original = printf("[%#X]\n", -7);
	myfunc = ft_printf("[%#X]\n", -7);
	
	printf("\n");

	original = printf("[%#X]\n", 1560133635);
	myfunc = ft_printf("[%#X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#X]\n", -2035065302);
	myfunc = ft_printf("[%#X]\n", -2035065302);
	
	printf("\n");

	printf("=============== SHARP # + MIN FIELD TESTS ================\n");

	original = printf("[%#3x]\n", 0);
	myfunc = ft_printf("[%#3x]\n", 0);
	
	printf("\n");

	original = printf("[%#3x]\n", -7);
	myfunc = ft_printf("[%#3x]\n", -7);
	
	printf("\n");

	original = printf("[%#3x]\n", 1560133635);
	myfunc = ft_printf("[%#3x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#3x]\n", -2035065302);
	myfunc = ft_printf("[%#3x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#14X]\n", 0);
	myfunc = ft_printf("[%#14X]\n", 0);
	
	printf("\n");

	original = printf("[%#14X]\n", 3);
	myfunc = ft_printf("[%#14X]\n", 3);
	
	printf("\n");

	original = printf("[%#14X]\n", -7);
	myfunc = ft_printf("[%#14X]\n", -7);
	
	printf("\n");

	original = printf("[%#14X]\n", 1560133635);
	myfunc = ft_printf("[%#14X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#14X]\n", -2035065302);
	myfunc = ft_printf("[%#14X]\n", -2035065302);
	
	printf("\n");

	printf("=============== SHARP # + ZEROPAD + MIN FIELD TESTS ================\n");

	original = printf("[%#03x]\n", 0);
	myfunc = ft_printf("[%#03x]\n", 0);
	
	printf("\n");

	original = printf("[%#03x]\n", -7);
	myfunc = ft_printf("[%#003x]\n", -7);
	
	printf("\n");

	original = printf("[%#3x]\n", 1560133635);
	myfunc = ft_printf("[%#03x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#03x]\n", -2035065302);
	myfunc = ft_printf("[%#03x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#014X]\n", 0);
	myfunc = ft_printf("[%#014X]\n", 0);
	
	printf("\n");

	original = printf("[%#014X]\n", 3);
	myfunc = ft_printf("[%#014X]\n", 3);
	
	printf("\n");

	original = printf("[%#014X]\n", -7);
	myfunc = ft_printf("[%#014X]\n", -7);
	
	printf("\n");

	original = printf("[%#014X]\n", 1560133635);
	myfunc = ft_printf("[%#014X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#014X]\n", -2035065302);
	myfunc = ft_printf("[%#014X]\n", -2035065302);
	
	printf("\n");

	printf("=============== SHARP # + PRECISION TESTS ================\n");

	original = printf("[%#.3x]\n", 0);
	myfunc = ft_printf("[%#.3x]\n", 0);
	
	printf("\n");

	original = printf("[%#.3x]\n", -7);
	myfunc = ft_printf("[%#.3x]\n", -7);
	
	printf("\n");

	original = printf("[%#.3x]\n", 1560133635);
	myfunc = ft_printf("[%#.3x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#.3x]\n", -2035065302);
	myfunc = ft_printf("[%#.3x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#.14X]\n", 0);
	myfunc = ft_printf("[%#.14X]\n", 0);
	
	printf("\n");

	original = printf("[%#.14X]\n", 3);
	myfunc = ft_printf("[%#.14X]\n", 3);
	
	printf("\n");

	original = printf("[%#.14X]\n", -7);
	myfunc = ft_printf("[%#.14X]\n", -7);
	
	printf("\n");

	original = printf("[%#.14X]\n", 1560133635);
	myfunc = ft_printf("[%#.14X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#.14X]\n", -2035065302);
	myfunc = ft_printf("[%#.14X]\n", -2035065302);
	
	printf("\n");

	printf("=============== SHARP # + MIN FIELD + PRECISION TESTS ================\n");

	original = printf("[%#5.3x]\n", 0);
	myfunc = ft_printf("[%#5.3x]\n", 0);
	
	printf("\n");

	original = printf("[%#5.3x]\n", -7);
	myfunc = ft_printf("[%#5.3x]\n", -7);
	
	printf("\n");

	original = printf("[%#5.3x]\n", 1560133635);
	myfunc = ft_printf("[%#5.3x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#5.3x]\n", -2035065302);
	myfunc = ft_printf("[%#5.3x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#5.7X]\n", 0);
	myfunc = ft_printf("[%#5.7X]\n", 0);
	
	printf("\n");

	original = printf("[%#5.7X]\n", 3);
	myfunc = ft_printf("[%#5.7X]\n", 3);
	
	printf("\n");

	original = printf("[%#5.7X]\n", -7);
	myfunc = ft_printf("[%#5.7X]\n", -7);
	
	printf("\n");

	original = printf("[%#5.7X]\n", 1560133635);
	myfunc = ft_printf("[%#5.7X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#5.7X]\n", -2035065302);
	myfunc = ft_printf("[%#5.7X]\n", -2035065302);
	
	printf("\n");

	printf("=============== SHARP # + ZERO PAD + MIN FIELD + PRECISION TESTS ================\n");

	original = printf("[%#05.3x]\n", 0);
	myfunc = ft_printf("[%#05.3x]\n", 0);
	
	printf("\n");

	original = printf("[%#05.3x]\n", -7);
	myfunc = ft_printf("[%#05.3x]\n", -7);
	
	printf("\n");

	original = printf("[%#05.3x]\n", 1560133635);
	myfunc = ft_printf("[%#05.3x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#05.3x]\n", -2035065302);
	myfunc = ft_printf("[%#05.3x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#05.7X]\n", 0);
	myfunc = ft_printf("[%#05.7X]\n", 0);
	
	printf("\n");

	original = printf("[%#05.7X]\n", 3);
	myfunc = ft_printf("[%#05.7X]\n", 3);
	
	printf("\n");

	original = printf("[%#05.7X]\n", -7);
	myfunc = ft_printf("[%#05.7X]\n", -7);
	
	printf("\n");

	original = printf("[%#05.7X]\n", 1560133635);
	myfunc = ft_printf("[%#05.7X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#05.7X]\n", -2035065302);
	myfunc = ft_printf("[%#05.7X]\n", -2035065302);
	
	printf("\n");
	
	printf("=============== SHARP # + LEFT + MIN FIELD + PRECISION TESTS ================\n");

	original = printf("[%#-5.3x]\n", 0);
	myfunc = ft_printf("[%#-5.3x]\n", 0);
	
	printf("\n");

	original = printf("[%#-5.3x]\n", -7);
	myfunc = ft_printf("[%#-5.3x]\n", -7);
	
	printf("\n");

	original = printf("[%#-20.3x]\n", 1560133635);
	myfunc = ft_printf("[%#-20.3x]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#-20.3x]\n", -2035065302);
	myfunc = ft_printf("[%#-20.3x]\n", -2035065302);
	
	printf("\n");

	original = printf("[%#-20.7X]\n", 0);
	myfunc = ft_printf("[%#-20.7X]\n", 0);
	
	printf("\n");

	original = printf("[%#-20.7X]\n", 3);
	myfunc = ft_printf("[%#-20.7X]\n", 3);
	
	printf("\n");

	original = printf("[%#-20.7X]\n", -7);
	myfunc = ft_printf("[%#-20.7X]\n", -7);
	
	printf("\n");

	original = printf("[%#-20.7X]\n", 1560133635);
	myfunc = ft_printf("[%#-20.7X]\n", 1560133635);
	
	printf("\n");

	original = printf("[%#-20.7X]\n", -2035065302);
	myfunc = ft_printf("[%#-20.7X]\n", -2035065302);
	
	printf("\n");
	
	printf("=============== 'u' TESTS ================\n");
	
	original = printf("[%+u]\n", 1024u);
	myfunc = ft_printf("[%+u]\n", 1024u);
	
	printf("\n");
	
	original = printf("[%+u]\n", -1024u);
	myfunc = ft_printf("[%+u]\n", -1024u);
	
	printf("\n");

	original = printf("[% u]\n", 1024u);
	myfunc = ft_printf("[% u]\n", 1024u);
	
	printf("\n");
	
	original = printf("[% u]\n", -1024u);
	myfunc = ft_printf("[% u]\n", -1024u);
	
	printf("\n");
	
	original = printf("[% 0-+*.*u]\n", 20, 5, 1024u);
	myfunc = ft_printf("[% 0-+*.*u]\n", 20, 5, 1024u);
	
	printf("\n");

	printf("=============== 's' TESTS ================\n");

	original = printf("[%020.5s]\n", "Hallo heimur");
	myfunc = ft_printf("[%020.5s]\n", "Hallo heimur");
	
	printf("\n");

	printf("=============== SUPER FLAGS TESTS ================\n");

	original = printf("[%+ -0*.*x]\n", 20, 10, -0x1234abcdu);
	myfunc = ft_printf("[%+ -0*.*x]\n", 20, 10, -0x1234abcdu);
	
	printf("\n");

	original = printf("[% 182.51%][%'-27.73d][%5.132s][%#-116.131x][%00*.137X]\n" , 32480236, "V4WE", 3639305080u, -188, 2672700428u);
	myfunc = ft_printf("[% 182.51%][%'-27.73d][%5.132s][%#-116.131x][%00*.137X]\n" , 32480236, "V4WE", 3639305080u, -188, 2672700428u);
	
	printf("\n");

	original = printf("[%117.153s][%0193.115x][% 0141.106d][%'++6.46d][%*p]\n" ,"%=#]t", 1948872082u, 109995835, -258740, -66, (void*)5538646285460349221lu);
	myfunc = ft_printf("[%117.153s][%0193.115x][% 0141.106d][%'++6.46d][%*p]\n" ,"%=#]t", 1948872082u, 109995835, -258740, -66, (void*)5538646285460349221lu);
	
	printf("\n");

	original = printf("[%'157.u]\n" ,931783111u);
	myfunc = ft_printf("[%'157.u]\n" ,931783111u);
	
	printf("\n");

	original = printf("[%0110.26u][%-151.155x][%0+20.122%]\n", 2591018974u, 2531434124u);
	myfunc = ft_printf("[%0110.26u][%-151.155x][%0+20.122%]\n", 2591018974u, 2531434124u);
	
	printf("\n");

	original = printf("[%0'83i][% -119.19%][%-23.129d][%112.163s]\n", 1932769910, 1382201723, NULL);
	myfunc = ft_printf("[%0'83i][% -119.19%][%-23.129d][%112.163s]\n", 1932769910, 1382201723, NULL);
	
	printf("\n");

	original = printf("[%-39p][%##58.X][%' *.*d][%--171.111X]\n", (void*)5552234905102446334lu, 1390511942u, 133, -40, 71290271, 2718578726u);
	myfunc = ft_printf("[%-39p][%##58.X][%' *.*d][%--171.111X]\n", (void*)5552234905102446334lu, 1390511942u, 133, -40, 71290271, 2718578726u);
	
	printf("\n");

	// checks leaks
	system("leaks a.out > leaks_main.txt");
}
