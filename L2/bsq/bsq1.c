/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:49:15 by kmaeda            #+#    #+#             */
/*   Updated: 2026/03/20 12:49:16 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv) {
	if (argc < 2) {
		process_file("-");
		fputc('\n', stdout);
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		process_file(argv[i]);
		fputc('\n', stdout);
	}
	return 0;
}
