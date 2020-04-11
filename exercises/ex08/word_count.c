#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <glib/gprintf.h>

void increment(GHashTable *hash, gchar* key)
{
  if(g_hash_table_contains (hash,key))
  {
    gint* value = (gint*) g_hash_table_lookup(hash,key);
    *value +=1;
  }
  else
  {
    gint * value_new = g_new(gint,1);
    *value_new = 1;
    g_hash_table_insert(hash,key,value_new);
  }
}

GHashTable* split_words(gchar* filename)
{
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  gchar **text = g_new(gchar*,1);
  gsize *length = g_new(gsize,1);
  GError **error = g_new(GError*,1);
  gboolean f = g_file_get_contents(filename,text,length,error);
  gchar **words = g_strsplit(*text," ",30000);
  for(guint i = 0; i<g_strv_length(words);i++)
  {
    increment(hash,words[i]);
  }
  return hash;
}

void print_words()
{
  GHashTable* ht = split_words("Alice.txt");
  guint *len = g_new(guint,1);
  gchar** keys = (gchar**) g_hash_table_get_keys_as_array (ht, len);
  for (guint i = 0; i < *len; i++)
  {
    gint* val = (gint*) g_hash_table_lookup(ht,keys[i]);
    g_printf("%s %i \n",keys[i],*val);
  }
}

int main(int argc, char** argv) {
  print_words();
  return 0;
}
