# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Maintainer: Konstantin Gizdov <arch@kge.pw>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=3.1.0
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.io/'
depends=('java-environment=11' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf' 'python')
options=('!distcc' '!strip')
source=("https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip"
        "https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig")
sha512sums=('2e28b200af9b6075d406eb946c852005b0eefca2328138d42e5010520a5ac952d72276c9ed8d3a9750bfb1f167a068827ef6b94450c708f8e7140ffcaa29755c'
            'SKIP')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

build() {
  env EXTRA_BAZEL_ARGS="--host_javabase=@local_jdk//:jdk" ./compile.sh
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
