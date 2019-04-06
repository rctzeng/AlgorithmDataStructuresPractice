class Solution(object):
    """
    Sorting: (Nlog N)
    """
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        emails = [self.processEmail(email) for email in emails]
        emails = sorted(emails)
        distinct_emails = [emails[0]]
        for email in emails[1:]:
            if email==distinct_emails[-1]: continue
            distinct_emails += [email]
        return len(distinct_emails)

    def processEmail(self, email):
        result = []
        SkipFlag = False
        i = 0
        for i in range(len(email)):
            if email[i]=='@':
                result = ''.join(result)+email[i:]
                break
            if email[i]=='.': continue
            if email[i]=='+': SkipFlag = True
            if SkipFlag: continue
            result += [email[i]]
        return result
