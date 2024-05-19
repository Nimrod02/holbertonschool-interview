#!/usr/bin/python3
"""module - count_words"""

import re
import requests


def count_words(subreddit, word_list):
    """Count the number of times a word appears in the titles of hot posts

    Args:
        subreddit (str): subreddit to search
        word_list (list): list of words to count

    Returns:
        None
    """

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {
        'User-Agent': 'Python/requests:APIproject:0.0.1 (by /u/veeteeran)'
    }
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return None

    hot_posts = response.json().get('data', {}).get('children', [])
    hot_titles = [post.get('data', {}).get('title', '') for post in hot_posts]

    word_count = {word.lower(): 0 for word in word_list}
    for title in hot_titles:
        for word in word_list:
            word_count[word.lower()] += len(
                re.findall(
                    r'\b{}\b'.format(re.escape(word)), title, re.IGNORECASE
                )
            )

    sorted_words = sorted(
        word_list, key=lambda x: (-word_count[x.lower()], x.lower())
    )
    for word in sorted_words:
        if word_count[word.lower()] > 0:
            print(f'{word.lower()}: {word_count[word.lower()]}')
