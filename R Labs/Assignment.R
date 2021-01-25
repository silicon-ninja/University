data <- data.frame (Price=c(120, 106 ,95 ,70 ,65, 58),Number_Ordered=c(90, 115 ,121, 138, 155, 182))
data
plot(data$Price,data$Number_Ordered)
linmod = lm(data$Number_Ordered ~ data$Price)
abline(data$Price ~ data$Number_Ordered)
abline(linmod, col="blue")

