class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        emails = set(emails)

        address = set()
        for e in emails:
            local,domain = e.split('@')
            name = (local.split('+')[0].replace('.','') , domain)
            address.add(name)
        
        return len(address)