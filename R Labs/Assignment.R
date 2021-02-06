# K Srikanth 17ETCS002124
data <- data.frame (Number_Ordered=c(90, 115 ,121, 138, 155, 182),Price=c(120, 106 ,95 ,70 ,65, 58))
data
plot(data$Number_Ordered,data$Price)
linmod = lm(data$Price ~ data$Number_Ordered)
abline(data$Number_Ordered ~ data$Price)
abline(linmod, col="blue")
linmod




