# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Maintainer: Konstantin Gizdov <arch@kge.pw>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=4.2.0
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.build/'
depends=('java-environment=11' 'libarchive' 'zip' 'unzip')
makedepends=('gcc10' 'git' 'protobuf' 'python')
options=('!distcc' '!strip')
source=("https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip"
        "https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig")
sha512sums=('0ce338cbe10be3e26f63afa46d66d49c2b234dfdf9d8b766230cfba1cac6f8570973d5d26072420186e0514e3f3e64faddfed04df523a7154a8bc898d860882a'
            'SKIP')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

build() {
  # https://github.com/bazelbuild/bazel/issues/13613
  CC=/usr/bin/gcc-10 \
  CXX=/usr/bin/g++-10 \
  EMBED_LABEL=$pkgver EXTRA_BAZEL_ARGS="--host_javabase=@local_jdk//:jdk" ./compile.sh
  # https://github.com/bazelbuild/bazel/issues/13613
  CC=/usr/bin/gcc-10 \
  CXX=/usr/bin/g++-10 \
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
