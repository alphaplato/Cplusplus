xgboost实现中Booster类get_score方法输出特征重要性:
其中importance_type参数支持三种特征重要性的计算方法： 
> 1.importance_type=weight（默认值），特征重要性使用特征在所有树中作为划分属性的次数。 
> 2.importance_type=gain，特征重要性使用特征在作为划分属性时loss平均的降低量。  
> 3.importance_type=cover，特征重要性使用特征在作为划分属性时对样本的覆盖度。  

特征重要性可以用来做模型可解释性，这在风控等领域是非常重要的方面。