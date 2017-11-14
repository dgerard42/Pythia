/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weather.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:55:35 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/11 19:32:18 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "curl/curl.h"
# include <stdio.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl)
  {
	curl_easy_setopt(curl, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/forecast?id=5350734&APPID=63a2d3979cc5bd07ac40b00665b90566");
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	res = curl_easy_perform(curl);
	if(res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
	printf("%u\n", res);
    curl_easy_cleanup(curl);
  }
  return 0;
}

//Fremont, CA 5350734
//San Francisco, CA 5391959
//Palo Alto, CA 5380748
//San Jose, CA 5392171
//Oakland, CA 5378538
//Berkley, CA 5327684
//Los Angeles, CA 5368361
//New York, NY 5128581
//Newark, DE 4143861
//Greenville, SC 4580549
//Seattle, WA 5809844
//Philadelphia, PA 4560349
//Sarasota, FL 4172131
