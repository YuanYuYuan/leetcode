class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        def str2num(num: str):
            parsed = num.split("+")
            real = int(parsed[0])
            imag = int(parsed[1][:-1])
            return (real, imag)

        def num2str(real, imag):
            return "%d+%di" % (real, imag)

        num1_real, num1_imag = str2num(num1)
        num2_real, num2_imag = str2num(num2)
        return num2str(
            num1_real * num2_real - num1_imag * num2_imag,
            num1_real * num2_imag + num1_imag * num2_real
        )

print(Solution().complexNumberMultiply("1+1i", "1+1i"))

print("0+2i")

print(Solution().complexNumberMultiply("1+-1i", "1+-1i"))
print("0+-2i")
