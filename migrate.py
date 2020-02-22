#!/usr/bin/env python3

from slugify import slugify
import time
import feedparser
import subprocess
import toml
from datetime import datetime
from time import mktime
import os

feed = feedparser.parse("https://flipdot.org/blog/rss.php?version=2.0&all=1")

for item in feed['items']:
  frontmatter = {
    'title': item.title,
    'date': datetime.fromtimestamp(mktime(item.published_parsed)),
    'author': item.authors[0].name,
  }

  body = ''.join([content.value for content in item.content])

  slug = slugify(item.title)
  date_string = time.strftime('%Y-%m-%d', item.published_parsed)

  filename = f'{date_string}-{slug}'

  # create folders
  os.makedirs('migrate/md', exist_ok=True)
  os.makedirs('migrate/html', exist_ok=True)

  html_path = f'./migrate/html/{filename}.html'
  with open(html_path, 'w') as f:
    f.write(body)

  md_path = f'./migrate/md/{filename}.md'

  pandoc = subprocess.run(["pandoc", html_path, "--to", "gfm", "-o", "/dev/stdout"], capture_output=True)

  with open(md_path, 'w') as f:
    f.write("+++\n")
    f.write(toml.dumps(frontmatter))
    f.write("+++\n")
    f.write(pandoc.stdout.decode('utf-8'))
