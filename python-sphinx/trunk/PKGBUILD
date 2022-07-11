# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=5.0.2
pkgrel=3
pkgdesc='Python documentation generator'
arch=('any')
url=http://www.sphinx-doc.org/
license=('BSD')
depends=('python-babel'
         'python-docutils'
         'python-imagesize'
         'python-jinja'
         'python-packaging'
         'python-pygments'
         'python-requests'
         'python-snowballstemmer'
         'python-sphinx-alabaster-theme'
         'python-sphinxcontrib-'{{apple,dev,html}help,jsmath,qthelp,serializinghtml})
makedepends=('python-setuptools')
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-html5lib'
              'python-pytest'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc}
        'sphinx-use-get_settings.patch::https://github.com/sphinx-doc/sphinx/commit/8d99168794ab8be0de1e6281d1b76af8177acd3d.patch')
sha256sums=('b18e978ea7565720f26019c702cd85c84376e948370f1cd43d60265010e1c7b0'
            'SKIP'
            'ac64c53c1d64a41cbe9d76d8440f169614cd4a7b63286583d37bc64f64781fc5')
b2sums=('a2cbf8efca673d15e364d0db74a8c5e2c0ff469f2a102317fb9bf23aac12c12ced2593e3a5e2dd0ee2bc114f2018356d382d601a3c7ff9b2943e38b59fe45db4'
        'SKIP'
        'dbc83bac75e802915e6720975a27110d52e9721ac714fbc6dc579b7bcde9ed80ec13fa3a628bdec5fe4f4792e45300f47429ff92a6a5d9080037f690aef3f40c')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa <shimizukawa@gmail.com>

prepare() {
  cd Sphinx-$pkgver
  sed -i 's/0.19/0.20/' setup.py
  patch --forward --strip=1 --input=../sphinx-use-get_settings.patch
}

build() {
  cd Sphinx-$pkgver
  make build
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" make test
}

package() {
  cd Sphinx-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
