## SRS Documentation
- Functional Requirement
- Non-functional Requirement
- Goal of Implementation

## 1. Functional Requirement
 - ### Role Based Authentication    
    1. Login: through username and password.
    2. SighUp: through email, username, password.
- ### User Interface(UI):
    - #### Role 1: Admin:
        1. Job Posted
        2. Job Creation
        3. Candidate Management
        4. Complaints
    - #### Role 2: Client:
        1. Register/ Login
        2. Jobs Available
        3. Application Portal
        4. Application Tracking
        5. Profile
- ### Database:
    1. MongoDb Atlas for remote document Database
    2. for storing client and recruiter records
    3. AWS S3 for stpring resume and static files
- ### Backend:
    1. REST API 
    2. Express
    3. JWT for authentication
- ### Deployment:
    1. The Application is containerized in docker
    2. Hostd on EC2 machine on AWS
    3. Github Actions for CI/CD
### 2. Non Functional Requirement:
1. Clean and Responsive UI
2. Scalable and Reliable 
3. Performance
4. Data Privacy
5. Security

## 3. Goal of Implementation
1. Stramline Recruitment System
2. Enhanced Candidate Expierence
3. Improve Recruitment Outcome
4. Increase Efficiency 