# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Maintainer: Konstantin Gizdov <arch@kge.pw>
# Contributor: Frederik Schwan <frederik dot schwan at linux dot com>
# Contributor: Simon Legner <Simon.Legner@gmail.com>

pkgname=bazel
pkgver=3.5.0
pkgrel=1
pkgdesc='Correct, reproducible, and fast builds for everyone'
arch=('x86_64')
license=('Apache')
url='https://bazel.build/'
depends=('java-environment=11' 'libarchive' 'zip' 'unzip')
makedepends=('git' 'protobuf' 'python')
options=('!distcc' '!strip')
source=("https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip"
        "https://github.com/bazelbuild/bazel/releases/download/${pkgver}/bazel-${pkgver}-dist.zip.sig"
        https://github.com/bazelbuild/bazel/commit/5bf6eddd729064d90113087b1bbd81e3e1b8cec5.patch
        https://github.com/bazelbuild/bazel/commit/c8e8fd7b713cd9df1c460ea2b40cb40a369a6e3a.patch)
sha512sums=('d9e1bac8422b48474709cae5b5a1cba2d71780e2666594d397d874bb86bb13e53b4b953800b4eb50c2a02385fa576bf7b4c2a71534bf13fbdb03d8b96a481f6a'
            'SKIP'
            'b0585949b46dccdf3ce33eaa151203363153855888410bf22524fc7a8d492b675e76ab65a60e5fb142ca0c0e383743841b987ef985926db94e74d2b15659ab48'
            '1897b9db442b7589dbc69ca1390314ae0da1b2b01e6f49c0b9a7e7fb1cc8cb9681979370be03ef21d58a4e8a67cb49568b4d00d87db7a5167a2b7e8a46c58a5d')
validpgpkeys=('71A1D0EFCFEB6281FD0437C93D5919B448457EE0')

prepare() {
  patch -Np1 -i 5bf6eddd729064d90113087b1bbd81e3e1b8cec5.patch
  patch -Np1 -i c8e8fd7b713cd9df1c460ea2b40cb40a369a6e3a.patch
}

build() {
  EMBED_LABEL=$pkgver EXTRA_BAZEL_ARGS="--host_javabase=@local_jdk//:jdk" ./compile.sh
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
