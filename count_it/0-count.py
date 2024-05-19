#!/usr/bin/python3
"""module - count_words
"""

import re
import requests


def count_words(subreddit, word_list):
    """Count the number of times a word appears in the titles of hot posts

    Args:
        subreddit : subreddit to search
        word_list : list of words to count

    Returns:
        None
    """

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = \
        {'User-Agent': 'Python/requests:APIproject:0.0.1 (by /u/veeteeran)'}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return None

    hot_posts = response.json().get('data').get('children')
    hot_titles = [post.get('data').get('title') for post in hot_posts]

    word_count = {}
    for word in word_list:
        word_count[word] = 0
        for title in hot_titles:
            word_count[word] += len(re.findall(
                r'\b{}\b'.format(word), title, re.IGNORECASE))

    for word in sorted(word_list, key=lambda x: (-word_count[x], x)):
        if word_count[word] > 0:
            print('{}: {}'.format(word.lower(), word_count[word]))
