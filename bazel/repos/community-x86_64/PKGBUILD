# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=0.5.1
pkgrel=3
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('i686' 'x86_64')
license=('Apache')
url='https://bazel.io/'
depends=('java-environment>=8' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf')
options=('!distcc' '!strip')
source=(https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip
        https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig)
sha512sums=('7d35d74cfe568e09242b509779b54ac50a430da1474c39a6c96cea518ddcda6dcfb7dc29124518cda5edb10d09cf71b1f97e50857de53fbbf65ab979152b479e'
            'SKIP')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

build() {
  ./compile.sh
  ./output/bazel build scripts:bazel-complete.bash
  cd output
  ./bazel shutdown
}

package() {
  install -Dm755 ${srcdir}/output/bazel ${pkgdir}/usr/bin/bazel
  install -Dm755 ${srcdir}/bazel-bin/scripts/bazel-complete.bash ${pkgdir}/etc/bash_completion.d/bazel-complete.bash
  install -Dm755 ${srcdir}/scripts/zsh_completion/_bazel ${pkgdir}/usr/share/zsh/site-functions/_bazel
  mkdir -p ${pkgdir}/opt/bazel/
  for d in examples third_party tools; do
    cp -r ${srcdir}/${d} ${pkgdir}/opt/bazel/
  done
}
# vim:set ts=2 sw=2 et:
