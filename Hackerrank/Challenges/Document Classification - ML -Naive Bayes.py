
import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import CountVectorizer

input_file = "trainingdata.txt"

train_data, train_target = [], []
with open(input_file) as f:
    num_samples = f.readline()
    num_samples = int(num_samples)    
    for line in f:
        train_target.append(line.split(' ', 1)[0])
        train_data.append(line.split(' ', 1)[1])        
    
train_data = np.asarray(train_data)      
train_target = np.asarray(train_target)

def pipeline_tfidf_nb():
    tfidf_vect = CountVectorizer( stop_words = "english", min_df = 1, ngram_range = (1,2))
    naive_bayes_clf = MultinomialNB(alpha = .045)
    return Pipeline([('vect', tfidf_vect),('nbclf',naive_bayes_clf)])
    
clf = pipeline_tfidf_nb()

clf.fit(train_data, train_target)


num_test_cases = input()
for i in range(int(num_test_cases)):
    test_data = raw_input()
    abc = []
    abc.append(test_data)
    test_data = np.asarray(abc)
    pre = clf.predict(test_data)
    print pre[0]



