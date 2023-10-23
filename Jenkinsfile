pipeline {
    agent any
    environment {
        // Define your GitHub repository URL and credentials here
        GITHUB_REPO = 'https://github.com/MohamedAbuelsoud/Stack_Module.git'
       // GITHUB_CREDENTIALS = credentials('your-credential-id')
    }
    stages {
    
        stage('Delete Previous builds'){
            steps{
               // script{
                    deleteDir() // This step deletes the current workspace
                    // sh 'pwd'
               // }
            }
        }
        
        stage('Checkout') {
            steps {
                script {
                    checkout([$class: 'GitSCM', branches: [[name: 'main']], userRemoteConfigs: [[url: env.GITHUB_REPO]]])
                }
            }
        }
        

        
        stage('Build Docker Image') {
            steps {
            //   cleanWs()
                script {
                    // --build-arg
                    def dockerImage = docker.build('stack_module:v0.1', '-f /home/abuelsoud/Adaptive/DEVOPS/Stack_Module/Dockerfile /home/abuelsoud/Adaptive/DEVOPS/Stack_Module')
                }
            }
        }
        stage('Run Docker Container') {
            steps {
                script {
                    def dockerImage = docker.build('stack_module:v0.1', '-f /home/abuelsoud/Adaptive/DEVOPS/Stack_Module/Dockerfile /home/abuelsoud/Adaptive/DEVOPS/Stack_Module')
                    dockerImage.inside {
                        sh 'cd /usr/src/App/build && ./App'
                    }
                }
            }
        }
    }
}
