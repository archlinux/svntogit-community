# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=4.0.1
pkgrel=2
pkgdesc='Python documentation generator'
arch=('any')
url=http://www.sphinx-doc.org/
license=('BSD')
depends=('python-babel'
         'python-docutils'
         'python-imagesize'
         'python-jinja'
         'python-pygments'
         'python-requests'
         'python-setuptools'
         'python-snowballstemmer'
         'python-sphinx-alabaster-theme'
         'python-sphinxcontrib-'{{apple,dev,html}help,jsmath,qthelp,serializinghtml})
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-html5lib'
              'python-pytest'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc}
        'https://github.com/sphinx-doc/sphinx/commit/85f58874ecd9feb391e24f9d0197bef5cc637a87.patch')
sha256sums=('cf5104777571b2b7f06fa88ee08fade24563f4a0594cf4bd17d31c47b8740b4c'
            'SKIP'
            '560978f9fe91b169af8acb84cedbd291e4837f658468648d6e6c891a5f1bac2e')
b2sums=('25ddb31a6db4eb1b76054be7026c327b47e33ec3efaa3eec70e5aae747931723baafe4b7b944ec4405589294698995bf7f5988187927f64db00ba77f44dccedc'
        'SKIP'
        'f4e84995fcaa77359becece089c8809e3472a743493b0126891b651871fc2d3e8f1d80fa9be86c063a155962ab8455af65ab92da96fda970bf2218d933446fc7')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa <shimizukawa@gmail.com>

prepare() {
  cd Sphinx-$pkgver
  patch -p1 <"$srcdir"/85f58874ecd9feb391e24f9d0197bef5cc637a87.patch
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
  export PYTHONHASHSEED=0
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
