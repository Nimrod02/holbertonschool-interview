#!/usr/bin/python3
"""module - 0
"""

def canUnlockAll(boxes):
        """Determines if all the boxes can be opened.
        Args:
                boxes (list): list of lists of integers.
        
        Returns:
                True if all boxes can be opened, else return False.
        """
        if len(boxes) == 0:
                return False
        if len(boxes) == 1:
                return True
        keys = [0]
        for key in keys:
                for box in boxes[key]:
                        if box not in keys and box < len(boxes):
                                keys.append(box)
        if len(keys) == len(boxes):
                return True
        return False