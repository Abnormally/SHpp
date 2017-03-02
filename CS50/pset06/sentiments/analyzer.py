import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.lib = {}
        # TODO
        self.lib['positive'] = frozenset(x.strip().lower() for x in open(positives) if not x.startswith(';'))
        self.lib['negative'] = frozenset(x.strip().lower() for x in open(negatives) if not x.startswith(';'))

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        # TODO
        text = text.split(' ')
        result = 0
        
        for word in text:
            word = word.lower()
            
            if word in self.lib['positive']:
                result += 1
            elif word in self.lib['negative']:
                result -= 1
        
        return result