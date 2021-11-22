/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2021, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include <stdio.h>

#include <curl/curl.h>

/* <DESC>
 * Get a single file from an FTP server.
 * </DESC>
 */

struct FtpFile {
  const char *filename;
  FILE *stream;
};

static size_t my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream)
{
  struct FtpFile *out = (struct FtpFile *)stream;
  if(!out->stream) {
    /* open file for writing */
    out->stream = fopen(out->filename, "wb");
    if(!out->stream)
      return -1; /* failure, cannot open file to write */
  }
  return fwrite(buffer, size, nmemb, out->stream);
}


int main(void)
{
  CURL *curl;
  CURLcode res;
  struct FtpFile ftpfile = {
    "/home/berke/Documents/blackbird.mp3", /* name to store the file as if successful */
    NULL
  };

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if(curl) {
    /*
     * You better replace the URL with one that works!
     */
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://154.82.111.99.sslip.io/dl2/CB-Kv3FEuHk9K5wp580Q9fRSP_niOOcMcclmlJO8Y8jRXmcHO1nnZZRs8M0J0lSTiU8vLTwYWy4Iuc0ja8NOoljs5p9fYTJwlO-Uimy2lo4Y3TB_c6fIHhOLrkwfEj8uCs5M1AgsUZCXS342DJl9VHopCh96gqbXCgsOLYBmXnibsIOnLwhWr-nCj98H1Ducfcqf34f35PQxcsrZwNBELA03zqokaPHsFD7q3SOSnCy81WnyqgGvmC402yqYLQa2mjUsUIwuYRaMp2dTYjmCW1LPZS4G_9r8k7fmXF09Z6MZ_sSi0-Bj0S4fCYmkaNanZS3i74jn5ZDmDffNXO2v0y9rsjQXEtdKCLwo1VwR6ePwTKZOF5XcLEv5Xvih-L7Q_y0TFHGVk7b6UccWcR4kSpggJqg75DO5zwVa7r7KlmnfwQneKJyZmzxG7JJ08UA_d3-islGDbAwBsS0-6JtJllugBvKfcPDdFenIOVZAmwBZu85qDQzEhcqdjaSM_dGs2NIXharBosZ0O5zSguoqEGNWusbvUmxOcB6nY3M-ouR1A7e6hrdoiAOIPNHTbws7MjuhlUVqP-0h4gRn8ZiIMmYYGAI-ScT9HxhTdYUWOaMBuJCdvpGkMbSkwuJPpbtBWYZILVveRtT6X82U4e8cPUbrluD4JcICUq_wscsYU71wWz1xgXzKOVyl_3yxhPI2-KaMyIECMujjKbuUccz9mBv4Z6mpWKu-kDRYe5vTIZZXngVlZHdypgHh04oxfoHHujS25Imiw44KOOd8cmKG7qGh8QnsUARJQNKjt7klcCPiv_319VrNnBu5JdRliehx9OSXzgjxzHG1R-DCtf-H-RCMWpVqlyV4sdBXyHsfTGQYR251KuR0ZdZizYF63mMBJTQeUkINva8n4SZBKdmnPVhz7mSfH8VbXYmFvmvXo7ujcbSzOYfxoJV8SF36M8CjP21QKIqr4YRp6zTHEFUTWUEGu_cjwMZOygHl0062lT7nmbA_hzXWMz52HT9vFtBwGo9hDAsot1cwHCLCrr5LkTdFCzPQP2Yp0Pc2pcpA7ZbgERDSIitAGuPig9R1axoMJo594UNPwLB0KbAB5RrY3B0Z0NkJ3ZLovqXclSk94bWVtKtQdUN2fEtJ5JxVB5uRz_9TPCEYW5VIDKQ3VDohjj9kiJ178EdVJnj4ZC_bDocGPUFAw2LdQ6odN36XP71DFsHyrm9-bSorbjiR7sHyKwjBhaGXYFv--3wB-NvmV-R_Cp0730nJRUUlMSZoyGyfXQ/j-5sk1XP");
    /* Define our callback to get called when there's data to be written */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_fwrite);
    /* Set a pointer to our struct to pass to the callback */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftpfile);

    /* Switch on full protocol/debug output */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);

    if(CURLE_OK != res) {
      /* we failed */
      fprintf(stderr, "curl told us %d\n", res);
    }
  }

  if(ftpfile.stream)
    fclose(ftpfile.stream); /* close the local file */

  curl_global_cleanup();

  return 0;
}
