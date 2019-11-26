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
        stage ('Configure build info') {
            steps {
                //rtBuildInfo (
                    // Build retention:
                    //maxBuilds: 1,
                    //maxDays: 2,
                    //doNotDiscardBuilds: ["3"],
                    //deleteBuildArtifacts: true
                    // Using the Jenkins job's build name and number.
                //)
                echo 'DISABLED: requires commercial license.'
                sh 'true'
            }
        }
        stage ('Publish build info') {
            steps {
                rtPublishBuildInfo (
                    serverId: 'art-1' // Obtain an Artifactory server instance, defined in Jenkins --> Manage:
                )
                //echo 'DISABLED: requires commercial license.'
                //sh 'true'
            }
        }
        stage('Configuring') {
            steps {
                echo '[STATUS]: Configuring...'
                sh 'cd sst-core; env PATH=/usr/local/bin:$PATH ./autogen.sh'
                sh 'cd sst-core; export INSTALL_DIR=$(date "+%Y/%m/%d/%H:%M:%S"); mkdir -p $PWD-installs/$INSTALL_DIR; ./configure --prefix=$PWD-installs/$INSTALL_DIR'
                //echo '[STATUS]: archiving artifacts...'
                //archiveArtifacts artifacts: 'sst-core/src/sst/core/*.o, sst-core/src/sst/core/**/*.o, sst-core/src/sst/core/libltdl/.libs/*.a', fingerprint: true
            }
        }
        stage('Download artifacts from art-1') {
            steps {
                rtDownload (
                    serverId: 'art-1',
                    spec: '''{
                        "files": [
                            {
                            "pattern": "generic-local/sst-core/src/sst/core/",
                            "target": "./"
                            },
                            {
                            "pattern": "generic-local/sst-core/src/sst/core/**/",
                            "target": "./"
                            }
                        ]
                    }'''

                    // Optional - Associate the downloaded files with the following custom build name and build number,
                    // as build dependencies.
                    // If not set, the files will be associated with the default build name and build number (i.e the
                    // the Jenkins job name and number).
                    //buildName: 'holy',
                    //buildNumber: '42'
                )
            }
        }
        stage('Build') {
            steps {
                sh 'cd sst-core; make -j4'
            }
        }
        stage('Upload artifacts to art-1') {
            steps {
                rtUpload (
                    serverId: 'art-1',
                    spec: '''{
                        "files": [
                            {
                            "pattern": "sst-core/src/sst/core/*.o",
                            "target": "generic-local/sst-core/src/sst/core/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/impl/partitioners/*.o",
                            "target": "generic-local/sst-core/src/sst/core/impl/partitioners/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/impl/timevortex/*.o",
                            "target": "generic-local/sst-core/src/sst/core/impl/timevortex/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/tinyxml/*.o",
                            "target": "generic-local/sst-core/src/sst/core/tinyxml/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/serialization/*.o",
                            "target": "generic-local/sst-core/src/sst/core/serialization/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/interprocess/*.o",
                            "target": "generic-local/sst-core/src/sst/core/interprocess/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/cfgoutput/*.o",
                            "target": "generic-local/sst-core/src/sst/core/cfgoutput/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/statapi/*.o",
                            "target": "generic-local/sst-core/src/sst/core/statapi/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/.libs/*.o",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/.libs/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/.libs/*.a",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/.libs/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/loaders/.libs/*.o",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/loaders/.libs/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/loaders/*.lo",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/loaders/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/*.lo",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/libltdl/lt__argz.h",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/libltdl/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/*.la",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/libltdl/.libs/*.la",
                            "target": "generic-local/sst-core/src/sst/core/libltdl/.libs/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/model/*.o",
                            "target": "generic-local/sst-core/src/sst/core/model/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/eli/*.o",
                            "target": "generic-local/sst-core/src/sst/core/eli/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/rng/*.o",
                            "target": "generic-local/sst-core/src/sst/core/rng/"
                            },
                            {
                            "pattern": "sst-core/src/sst/core/interfaces/*.o",
                            "target": "generic-local/sst-core/src/sst/core/interfaces/"
                            }
                        ]
                    }'''

                    // Optional - Associate the downloaded files with the following custom build name and build number,
                    // as build dependencies.
                    // If not set, the files will be associated with the default build name and build number (i.e the
                    // the Jenkins job name and number).
                    //buildName: 'holy',
                    //buildNumber: '42'
                )
            }
        }
        stage('Test') {
            when {
                environment name: 'RUN_TESTS', value: 'true'
            }
            steps {
                echo 'Testing..'
                sh 'cd sst-core; ./src/sst/core/sstunit -ojunit || true'
                junit 'sst-core/*.xml'
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
