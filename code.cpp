import pandas as pd

# 1. Sample Catalog (The 'Data' part of Data Science)
data = {
    'product_id': [101, 102, 103, 104],
    'title': ['iPhone 13', 'iPhone 15', 'iPhone 11', 'iPhone 14'],
    'price': [45000, 70000, 25000, 55000],
    'rating': [4.5, 4.8, 4.0, 4.6],
    'stock': [10, 50, 5, 20]
}

df = pd.DataFrame(data)

def rank_products_sasta(df):
    # 2. Preprocessing / Normalization
    # Min-Max Scaling: (Value - Min) / (Max - Min)
    
    # For price, we want the LOWEST to have the HIGHEST score
    df['price_score'] = 1 - (df['price'] - df['price'].min()) / (df['price'].max() - df['price'].min())
    
    # For rating, higher is better
    df['rating_score'] = (df['rating'] - df['rating'].min()) / (df['rating'].max() - df['rating'].min())
    
    # 3. Apply Weights (The 'Science' part)
    # We give 70% importance to Price and 30% to Rating
    df['final_score'] = (df['price_score'] * 0.7) + (df['rating_score'] * 0.3)
    
    # 4. Sort by the calculated score
    return df.sort_values(by='final_score', ascending=False)

# Get the ranked results
ranked_results = rank_products_sasta(df)
print(ranked_results[['title', 'price', 'rating', 'final_score']]
