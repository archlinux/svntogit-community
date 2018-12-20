# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=0.21.0
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.io/'
depends=('java-environment=10' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf' 'python')
options=('!distcc' '!strip')
source=(https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip
        https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig)
sha512sums=('96489dac0b0daf84c8711e5e11dc7d810c3a1f037e567bc5f3d5a3fb20d8eeeb512238ca9cace1c7f8b570687c43269abb037fb42a4c4b97392e0af7d45bb653'
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
