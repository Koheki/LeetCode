class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:

        def checker(text):
            email = []
            n,i = len(text),0
            while i < n:
                if text[i] == '@':
                    while i < n:
                        email.append(text[i])
                        i += 1
                elif text[i] == '+':
                    while text[i] != '@':
                        i += 1
                elif text[i] == '.':
                    i += 1
                else:
                    email.append(text[i])
                    i += 1
            return "".join(email)

        address = set()
        
        for e in emails:
            email = checker(e)
            if email not in address:
                address.add(email)

        return len(address)