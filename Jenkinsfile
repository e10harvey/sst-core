pipeline {
    agent any

        options {
            buildDiscarder(logRotator(numToKeepStr: '10'))
        }

        parameters {
            booleanParam name: 'RUN_TESTS', defaultValue: true, description: 'Run Tests?'
            booleanParam name: 'RUN_ANALYSIS', defaultValue: true, description: 'Run Static Code Analysis?'
            booleanParam name: 'DEPLOY', defaultValue: true, description: 'Deploy Artifacts?'
        }

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'env PATH=/usr/local/bin:$PATH ./autogen.sh'
                sh 'mkdir -p $PWD-installs/$(date "+%Y/%m/%d/%H:%M:%S")'
                sh './configure --prefix=$PWD-installs/$(date "+%Y/%m/%d/%H:%M:%S")'
                sh 'make'
                archiveArtifacts artifacts: 'src/sst/core/*.o, src/sst/core/**/*.o, src/sst/core/libltdl/.libs/*.a', fingerprint: true
            }
        }
        stage('Test') {
            when {
                environment name: 'RUN_TESTS', value: 'true'
            }
            steps {
                echo 'Testing..'
                sh 'pwd; ls'
                sh './src/sst/core/sstunit -n goodConfig -ojunit || true'
                junit '*.xml'
            }
        }
        stage('Analyse') {
            when {
                environment name: 'RUN_ANALYSIS', value: 'true'
            }
            steps {
                echo 'Static Analysis...'
            }
        }
        stage('Deploy') {
            when {
                environment name: 'DEPLOY', value: 'true'
                expression {
                    currentBuild.result == null || currentBuild.result == 'SUCCESS'
                }
            }
            steps {
                echo 'Deploying....'
                sh 'make install'
            }
        }
    }
}
