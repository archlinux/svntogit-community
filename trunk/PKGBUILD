# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=0.14.1
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.io/'
depends=('java-environment=8' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf' 'python')
options=('!distcc' '!strip')
source=(https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip
        https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig)
sha512sums=('02c7125438f060d8e5e25b91ce3ca76fac6681b4f12033d807955a4ca5a5c22a3508a7229581b7349f35f343911f8408f43f8d78d54601277576dd32539e4681'
            'SKIP')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

build() {
  ./compile.sh
  ./output/bazel build scripts:bazel-complete.bash
  cd output
  ./bazel shutdown
}

package() {
  install -Dm755 ${srcdir}/scripts/packages/bazel.sh ${pkgdir}/usr/bin/bazel
  install -Dm755 ${srcdir}/output/bazel ${pkgdir}/usr/bin/bazel-real
  install -Dm644 ${srcdir}/bazel-bin/scripts/bazel-complete.bash ${pkgdir}/usr/share/bash-completion/completions/bazel
  install -Dm644 ${srcdir}/scripts/zsh_completion/_bazel ${pkgdir}/usr/share/zsh/site-functions/_bazel
  mkdir -p ${pkgdir}/opt/bazel/
  for d in examples third_party tools; do
    cp -r ${srcdir}/${d} ${pkgdir}/opt/bazel/
  done
}
# vim:set ts=2 sw=2 et:
