# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=0.23.0
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.io/'
depends=('java-environment=10' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf' 'python' 'maven' 'gcc-libs'
             'zlib' 'python-setuptools' 'python2-setuptools')
options=('!distcc' '!strip')
source=(https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip
        https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig
        "protobuf-3.7.0.tgz::https://github.com/protocolbuffers/protobuf/archive/v3.7.0.tar.gz"
        "gtest-1.8.0.tar.gz::https://github.com/google/googletest/archive/release-1.8.0.tar.gz"
        "gtest-BUILD.bazel::https://raw.githubusercontent.com/google/googletest/v1.8.x/BUILD.bazel"
        "gtest-WORKSPACE::https://raw.githubusercontent.com/google/googletest/v1.8.x/WORKSPACE"
        protobuf_build.patch
        protobuf_examples.patch
        protobuf_googletest.patch
        protobuf_util_python.patch
        protobuf_version.patch
        main_protobuf_build.patch
        workspace.patch)
sha512sums=('e53cd008552d61eab00f94a73458b6ada5c0bcb659f6fc748d4178b6b7371f625def17f983b09b9e920710153e6fd1e15b53ca71d424e2b0a79cdd4c815af3bf'
            'SKIP'
            'c570ece1d42706982dd87f601af6b3dd1d788d1b150b543190d10d2f070c67f0d006726ec4eafd3b9234a679e7ef77ac9d97749414f53f619287a1f23a0b739c'
            '1dbece324473e53a83a60601b02c92c089f5d314761351974e097b2cf4d24af4296f9eb8653b6b03b1e363d9c5f793897acae1f0c7ac40149216035c4d395d9d'
            '104ed7a953e6f5edbc9ba83dfc89f7f8140b17533800bf42bb043cb8bdeb46aaffa8baad29b4498a91f6f9504b6cc6e734462f7586e4d227a531a26264893973'
            '8feab77750d869ee21ea0c18dc0e2941acfdab816d3ab13e80b7fecb8f5923c87ab6563ad48711dc1c7ed29fc7776010507dcd47f1e21da486cd7f6870da173d'
            'f32084c8e00a411782df07b5a625faf0a3177efd8bd59d07479e46d2a9c4716209b4119ad49144e0b36aba4a63979ed356e07e30ed87a0d78d3c2ea20cbcaee5'
            '196ff5f816c9d835aed92a678670ee24cdbd586e92303abad6a1d6a7a5c1e14d08a003d898176adb00f65d1372a599d2e6e2bd9ba97064292dbb3ae89c194012'
            '1adb79496c3306bf21f70deebca8aa710c6664dbee0c50e04f90f7bb4b01d76751a95593002238fc784fd72eaca49e123c5e7cb0545dad8352c5970a53fca67a'
            '37aaca6d300318cd92d8e4333a43dd11a0228c96d5140e1c32f01178342493875740c84cc4527013898d10fa451e3805d1948c53b5419dd4a35e6733d8c6b14e'
            '7da0920cbd531c59092a021d6f19285ac5d043432942d80cfe4806ff07f4396740b56a53331b066092aa592d1c477dd1021c1e8e5170d62ea649fab65c86333f'
            'd061b8164654eb3c3872cb1824ea854cdacf5c94c1483209747e8bc13d0d40a78f913ac988b72317c757c2ed14b3d9edbe82f366c71fa29517a236f142d3a101'
            '88cc6bc4e7bb1850bbc4eea8b578720b12ca765e6287b0e262f1aaf8b9403e88e316ff714ac11580f42c033f91966903ef77950ca166c8da513b97f0559ea9d2')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

prepare() {
  ## First stage of
  # Update protobuf as per instructions in
  # https://github.com/bazelbuild/bazel/blob/master/third_party/protobuf/README.md
  # with few modifications:
  #  - build Java protobuf modules with maven
  #  - use patches for consistency

  mkdir "${srcdir}/third_party/protobuf/3.7.0"
  cp -r "${srcdir}/protobuf-3.7.0"/* "${srcdir}/third_party/protobuf/3.7.0"
  cp -r "${srcdir}/googletest-release-1.8.0/googletest" "${srcdir}/third_party/protobuf/3.7.0/third_party/googletest/googletest"
  cp -r "${srcdir}/googletest-release-1.8.0/googlemock" "${srcdir}/third_party/protobuf/3.7.0/third_party/googletest/googlemock"
  cat "${srcdir}/gtest-BUILD.bazel" > "${srcdir}/third_party/protobuf/3.7.0/third_party/googletest/BUILD.bazel"
  cat "${srcdir}/gtest-WORKSPACE" > "${srcdir}/third_party/protobuf/3.7.0/third_party/googletest/WORKSPACE"
  sed -r 's|/usr/bin/env python|/usr/bin/env python2|' -i "${srcdir}/third_party/protobuf/3.7.0/third_party/googletest/googletest/scripts"/*.py
  rm -rf "${srcdir}/third_party/protobuf/3.6.1"
}

build() {
  ## Second stage of
  # Update protobuf as per instructions in
  # https://github.com/bazelbuild/bazel/blob/master/third_party/protobuf/README.md
  # with few modifications:
  #  - build Java protobuf modules with maven
  #  - use patches for consistency

  # prepare protobuf 3.7.0
  cd "${srcdir}/third_party/protobuf/3.7.0"
  ./autogen.sh
  cd third_party/googletest/googletest
  autoreconf -fiv
  ./configure
  make

  cd "${srcdir}/third_party/protobuf/3.7.0"
  cd third_party/googletest/googlemock
  autoreconf -fiv
  ./configure
  make

  cd "${srcdir}/third_party/protobuf/3.7.0"
  ./configure  # --prefix=/usr  # we are not gonna install
  make

  # build Java protobuf modules
  cd "${srcdir}/third_party/protobuf/3.7.0/java"
  mvn package -Dmaven.test.skip=true
  cp core/target/protobuf-java-3.7.0.jar "${srcdir}/third_party/protobuf/3.7.0/libprotobuf_java.jar"
  cp util/target/protobuf-java-util-3.7.0.jar "${srcdir}/third_party/protobuf/3.7.0/libprotobuf_java_util.jar"

  # clean protobuf dir
  mvn clean
  cd "${srcdir}/third_party/protobuf/3.7.0"
  make clean
  rm -rf .git .gitignore .gitmodules

  # adjust Bazel to use new version (can't be done sooner)
  cd "${srcdir}"
  patch -Np1 -i "${srcdir}/protobuf_build.patch"
  patch -Np1 -i "${srcdir}/protobuf_examples.patch"
  patch -Np1 -i "${srcdir}/protobuf_googletest.patch"
  patch -Np1 -i "${srcdir}/protobuf_util_python.patch"
  patch -Np1 -i "${srcdir}/protobuf_version.patch"
  patch -Np1 -i "${srcdir}/main_protobuf_build.patch"
  patch -Np1 -i "${srcdir}/workspace.patch"

  # compile Bazel
  ./compile.sh
  ./output/bazel build scripts:bazel-complete.bash
  cd output
  ./bazel shutdown
}

package() {
  install -Dm755 "${srcdir}/scripts/packages/bazel.sh" "${pkgdir}/usr/bin/bazel"
  install -Dm755 "${srcdir}/output/bazel" "${pkgdir}/usr/bin/bazel-real"
  install -Dm644 "${srcdir}/bazel-bin/scripts/bazel-complete.bash" "${pkgdir}/usr/share/bash-completion/completions/bazel"
  install -Dm644 "${srcdir}/scripts/zsh_completion/_bazel" "${pkgdir}/usr/share/zsh/site-functions/_bazel"
  mkdir -p "${pkgdir}/opt/bazel"
  for d in examples third_party tools; do
    cp -r "${srcdir}/${d}" "${pkgdir}/opt/bazel/"
  done
}
# vim:set ts=2 sw=2 et:
