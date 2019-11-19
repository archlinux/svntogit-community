# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>

_pkgname=poetry
pkgname=python-poetry
pkgver=0.12.17
pkgrel=1
pkgdesc="Python dependency management and packaging made easy"
arch=('any')
url="https://poetry.eustace.io/"
license=('MIT')
_deps=('cachecontrol' 'cachy' 'cleo' 'html5lib' 'jsonschema' 'lockfile'
       'pkginfo' 'pyparsing' 'pyrsistent' 'requests' 'requests-toolbelt'
       'shellingham' 'tomlkit')
depends=("${_deps[@]/#/python-}")
makedepends=('python-dephell')
checkdepends=('git' 'python-pytest' 'python-pytest-mock' 'python-httpretty')
provides=('poetry')
conflicts=('poetry')
replaces=('poetry')
source=("${_pkgname}-${pkgver}.tar.gz::https://github.com/sdispater/${_pkgname}/archive/${pkgver}.tar.gz"
        "https://github.com/sdispater/poetry/commit/02d78ba87c48ec7e5e979c9a3624c038235c4d50.patch"
        "poetry-completions-generator")
sha256sums=('ddce622d65685ea610563e711d68efa9b2cef8541f72ece5e6a36182ee23eb16'
            'eecddbd4ee8ed0033e0cf74b166f8fec3024658ce0d7e7b1f673a5d82dff12a9'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6')
b2sums=('f923933923d4e5fc13ea6d24da164634ac05038b81f3c1f7d18af05c153f77e4afa0f21a9ec6832caad0d10c2eb1638a66dfa9c8971d0f36c2c904b1024ca4cf'
        '9b387d1fbe81ce1280ee6cdb7fac671b41df9c23980463c7a2027da584864a6d7bf88af5f01aef24a440a55d204dea314547beafe5bf68e8854489929492d94b'
        '3fd62e7936d7547dcd06a1a7519f176a1597553ecc959144a4be799bb7e2d688e187f14604d3e359ed10c128c722ebd588c07ca318e0be0a31d276dcb388e2e1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # python 3.8 changed the abiflags to never include 'm'
    patch -p1 -i ../02d78ba87c48ec7e5e979c9a3624c038235c4d50.patch

    # poetry-generated setup.py are fatally broken, see:
    # https://github.com/sdispater/poetry/issues/866
    dephell deps convert --from pyproject.toml --to setup.py
}

build(){
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # only works inside git repositories
    python -m pytest -k 'not test_default_with_excluded_data '
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

    # install completions, which for some crazy reason hardcode the filename
    # used to invoke which is __main__.py if we use python -m poetry, and also
    # adds the full directory path???
    install -m755 ../poetry-completions-generator ./poetry-completions-generator
    ./poetry-completions-generator completions bash | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/bash-completion/completions/poetry
    ./poetry-completions-generator completions zsh | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/zsh/site-functions/_poetry
    ./poetry-completions-generator completions fish | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/fish/vendor_completions.d/poetry.fish
}
